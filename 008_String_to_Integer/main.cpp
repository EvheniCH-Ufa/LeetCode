#include <iostream>
#include <unordered_set>

class Solution {
public:
    int myAtoi(const std::string& str)
    {
        if (str.size() == 0)
        {
            return 0;
        }

        int index = str.find_first_not_of(' ', 0);
        if (index < 0)
        {
            return 0;
        }

        int result = 0;
        int znak = 1;

        if (str[index] == '+')
        {
            ++index;
        }
        else if (str[index] == '-')
        {
            znak = -1;
            ++index;
        }

        while (index < str.size())
        {
            int curr_num = str[index] - 48;
            if (curr_num >= 0 && curr_num <= 9)
            {
                //Диапазон допустимых значений типа int — от -2 147 483 648 до 2 147 483 647
                if (znak > 0 && (result > 214748364 || (result == 214748364 && curr_num > 6))) // overflow
                {
                    return 2'147'483'647;
                }
                else if (znak < 0 && (result > 214748364 || (result == 214748364 && curr_num > 7))) // overflow
                {
                    return -2'147'483'648;
                }

                result = result * 10 + curr_num;
            }
            else
            {
                return result * znak;
            }
            ++index;
        }
        return result * znak;
    }
};





int main()
{
    Solution sol;
    std::cout << sol.myAtoi("-2147483648") << std::endl; 			// 0
    std::cout << sol.myAtoi("42") << std::endl; 			// 42
    std::cout << sol.myAtoi("-042") << std::endl;           // -42
    std::cout << sol.myAtoi("1337c0d3") << std::endl;       // 1337
    std::cout << sol.myAtoi("0-1") << std::endl; 			// 0
    std::cout << sol.myAtoi("word and 987") << std::endl;   // 0
    std::cout << sol.myAtoi(    "-91283472332") << std::endl;   // 0
    std::cout << sol.myAtoi(    "91283472332") << std::endl;   // 0
        //                          2147483647



}

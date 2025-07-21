#include <iostream>

class Solution {
public:
    std::string intToRoman(int num)
    {
        std::string result(num/1000, 'M');

        num = num % 1000;

        {
            int count_100 = num / 100;
            int count_500 = count_100 / 5;
            int count_100_up_500 = count_100 - count_500 * 5;

            if (count_500)
            {
                if (count_100_up_500 == 4)
                {
                    result = result + "CM";
                }
                else
                {
                    result = result + "D" + std::string(count_100_up_500, 'C');
                }
            }
            else
            {
                if (count_100_up_500 == 4)
                {
                    result = result + "CD";
                }
                else
                {
                    result = result + std::string(count_100_up_500, 'C');
                }
            }
            num = num % 100;
        }


        {
            int count_10 = num / 10;
            int count_50 = count_10 / 5;
            int count_10_up_50 = count_10 - count_50 * 5;

            if (count_50)
            {
                if (count_10_up_50 == 4)
                {
                    result = result + "XC";
                }
                else
                {
                    result = result + "L" + std::string(count_10_up_50, 'X');
                }
            }
            else
            {
                if (count_10_up_50 == 4)
                {
                    result = result + "XL";
                }
                else
                {
                    result = result + std::string(count_10_up_50, 'X');
                }
            }
            num = num % 10;
        }


        {
            int count_1 = num;
            int count_5 = count_1 / 5;
            int count_1_up_5 = count_1 - count_5 * 5;

            if (count_5)
            {
                if (count_1_up_5 == 4)
                {
                    result = result + "IX";
                }
                else
                {
                    result = result + "V" + std::string(count_1_up_5, 'I');
                }
            }
            else
            {
                if (count_1_up_5 == 4)
                {
                    result = result + "IV";
                }
                else
                {
                    result = result + std::string(count_1_up_5, 'I');
                }
            }
        }
        return result;
    }
};



int main()
{
    Solution sol;

    std::cout << sol.intToRoman(3749) << std::endl; // MMMDCCXLIX
    std::cout << sol.intToRoman(58) << std::endl;   // LVIII
    std::cout << sol.intToRoman(1994) << std::endl; // MCMXCIV
}

/*

Symbol	Value
I	1
V	5
X	10
L	50
C	100
D	500
M	1000


*/

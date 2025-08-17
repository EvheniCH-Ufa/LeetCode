#include <iostream>

using namespace std;

class Solution {
public:
    std::string convert(std::string str, int numRows)
    {

        if (numRows == 1)
        {
            return str;
        }

        int heigt = numRows;
        int width_cikle = 2* numRows - 2;
        std::string result(str.size(), ' ');
        int pos = 0;
        for (int curr_elem = 0; curr_elem < str.size();)
        {
            result[pos] = str[curr_elem];
            ++pos;
            curr_elem += width_cikle;
        }

        for (int level = 1; level < heigt - 1; ++level)
        {
            for (int curr_elem = level; curr_elem < str.size();)
            {
                //  !!!add ifes range!!!
                if (curr_elem >=  str.size())
                {
                    continue;
                }
                result[pos] = str[curr_elem];
                ++pos;

                if (curr_elem + width_cikle - 2*level >=  str.size())
                {
                    curr_elem += width_cikle;
                    continue;
                }
                result[pos] = str[curr_elem + width_cikle - 2*level];
                ++pos;
                curr_elem += width_cikle;
            }
        }

        for (int curr_elem = heigt - 1; curr_elem < str.size();)
        {
            result[pos] = str[curr_elem];
            ++pos;
            curr_elem += width_cikle;
        }
        return result;
    }
};



int main()
{
    Solution sol;

    //   Example 1:
    //                Input: s = "PAYPALISHIRING", numRows = 3
    //        Output: "PAHNAPLSIIGYIR"
    std::cout << sol.convert("PAYPALISHIRING", 3) << std::endl;

    //  Example 2:
    //  Input: s = "PAYPALISHIRING", numRows = 4
    //  Output: "PINALSIGYAHRPI"
    std::cout << sol.convert("PAYPALISHIRING", 4) << std::endl;

    //  Example 3:
    //  Input: s = "A", numRows = 1
    //  Output: "A"}
    std::cout << sol.convert("A", 1) << std::endl;
}

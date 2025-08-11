#include <iostream>
#include<unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        auto res = CalcRec("("+ s + ")",0);
        return res.res;
    }


private:
    const 	unordered_map<char, int> SLOVAR = {
        {'0', 0},
        {'1', 1},
        {'2', 2},
        {'3', 3},
        {'4', 4},
        {'5', 5},
        {'6', 6},
        {'7', 7},
        {'8', 8},
        {'9', 9},
        };

    struct CalcRes
    {
        int res = 0;
        int pos = 0;
    };

    CalcRes CalcRec (const string& str, int start_pos)
    {
        int deystvie = 1;

        CalcRes result;

        int curr_num = 0;
        while (true)
        {
            if (start_pos >= str.size() )
            {
                return result;
            }

            auto it_find = SLOVAR. find(str[start_pos]);
            if (it_find!= SLOVAR.end() )
            {
                curr_num = curr_num*10+(it_find->second);
            }
            else if (str[start_pos] == '+')
            {
                result.res += deystvie * curr_num;
                curr_num = 0;

                deystvie = 1;
            }

            else if (str[start_pos] == '-')
            {
                result.res += deystvie * curr_num;
                curr_num = 0;
                deystvie = -1;
            }

            else if (str[start_pos] == '(')
            {
                auto loc_res = CalcRec(str, start_pos+1);
                result.res +=deystvie * loc_res.res;
                start_pos = loc_res.pos;
            }
            else if (str[start_pos] == ')')
            {
                result.res += deystvie *curr_num;
                result.pos = start_pos ;
                return result;
            }
            ++start_pos;
        }
    }
};


int main()
{
    Solution sol;

    string str = "(10 +(1+2+3)+7)";
    cout << sol.calculate(str) << endl;


    str= "(1+(4+5+2)-3)+(6+8)";
    cout << sol.calculate(str) << endl;

    str= "((5)-2)";
    cout << sol.calculate(str) << endl;

    str= "1 +1";
    cout << sol.calculate(str) << endl;

    str= " 2-1 + 2 ";
    cout << sol.calculate(str) << endl;

}

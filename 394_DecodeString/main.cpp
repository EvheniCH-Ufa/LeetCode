#include <iostream>
#include<unordered_map>
#include <string>

using namespace std;


class Solution {
public:
    string decodeString(const string& str)
    {
        auto result = decodeStringRec("1[" + str + ']', 0);
        return result.first;
    }

private:

    std::pair<std::string, int> decodeStringRec(const string& str, int start_pos) //in [...]
    {
        string result;

        int count_repead = 0;
        int pos = start_pos;
        while (pos < str.size())
        {
            auto it_find = SLOVAR.find(str[pos]); // 0...9
            if (it_find!= SLOVAR.end() )
            {
                count_repead = count_repead*10+(it_find->second);
            }
            else if (str[pos] == '[')
            {
                ++pos;
                auto curr_res = decodeStringRec(str, pos); //in [...]
                pos = curr_res.second;
                std::string append_str;
                append_str.reserve(curr_res.first.size() * count_repead);
                for (int i = 0; i < count_repead; ++i)
                {
                    append_str += curr_res.first;
                }
                result += append_str;
                count_repead = 0;
            }
            else if (str[pos] == ']')
            {
                return {result, pos};
            }
            else // symbols for append
            {
                result += str[pos];
            }
            ++pos;
        }
        return {result, pos+1};
    }


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
};

int main()
{
    Solution sol;
    {
        cout << "first" << endl;
        string str = "3[a]2[bc]";
        cout << sol.decodeString(str) << endl;
        //Output: "aaabcbc"
    }

    {
        cout << "second" << endl;
        string str = "3[a2[c]]";
        cout << sol.decodeString(str) << endl;
        //Output: "accaccacc"
                 //accaccacc
    }

    {
        cout << "triple" << endl;
        string str = "2[abc]3[cd]ef";
        cout << sol.decodeString(str) << endl;
        //Output: "abcabccdcdcdef"
//                 abcabccdcdcdef
    }
}

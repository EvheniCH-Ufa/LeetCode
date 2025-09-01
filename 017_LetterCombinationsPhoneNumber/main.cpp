#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

class Solution {
public:
    std::vector<std::string> letterCombinations(std::string digits)
    {
        std::vector<std::string> result;
        result.reserve(4*4*4*4);

        if(digits.empty())
        {
            return result;
        }


        int count0, count1, count2, count3;

        count0 = code.find(digits[0]) == code.end() ? 0 : code.find(digits[0])->second.size();
        count1 = code.find(digits[1]) == code.end() ? 0 : code.find(digits[1])->second.size();

        count2 = (digits.size() > 2 && code.find(digits[2]) != code.end()) ? code.find(digits[2])->second.size() : 0;
        count3 = (digits.size() > 3 && code.find(digits[3]) != code.end()) ? code.find(digits[3])->second.size() : 0;

        for(int i = 0; i < count0; ++i)
        {
            std::string res;
            res.push_back(code.find(digits[0])->second[i]);

            if(count1 == 0)
            {
                result.push_back(res);
            }
            else
            {

                for(int j = 0; j < count1; ++j)
                {
                    res.push_back(code.find(digits[1])->second[j]);

                    if (count2 == 0)
                    {
                        result.push_back(res);
                    }
                    else
                    {
                        for(int k = 0; k < count2; ++k)
                        {
                            res.push_back(code.find(digits[2])->second[k]);
                            if(count3 == 0)
                            {
                                result.push_back(res);
                            }
                            else
                            {
                                for(int l = 0; l < count3; ++l)
                                {
                                    res.push_back(code.find(digits[3])->second[l]);
                                    result.push_back(res);
                                    res.pop_back();
                                }
                            }

                            res.pop_back();
                        }
                    }
                    res.pop_back();
                }
            }
            res.pop_back();
        }

        return result;
    }

    std::unordered_map<char, std::string> code = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };

};



int main()
{
    Solution sol;

    auto res = sol.letterCombinations("23");

    bool is_first = true;
    std::cout << '[';
    for (const auto str : res)
    {
        if (!is_first)
        {
            std::cout << ',';
        }
        std::cout << str;

        is_first = false;
    }
    std::cout << ']' << std::endl;
}

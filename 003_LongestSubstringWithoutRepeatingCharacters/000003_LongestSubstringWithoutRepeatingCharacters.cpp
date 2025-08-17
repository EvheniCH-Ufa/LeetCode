// 000003_LongestSubstringWithoutRepeatingCharacters.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <vector>


class Solution {
public:
    int lengthOfLongestSubstring(std::string s)
    {
        std::vector<int> symbols_in_curr_posled(256, -1); // po kodu simvola nomer v posled

        std::string curr_posled;
        int maxlen = 0;
        for (char ch : s)
        {
            if (symbols_in_curr_posled[ch] >= 0)  // if curr_symbol exist in curr_posled
            {
                int curr_posled_size = curr_posled.size();
                maxlen = std::max(maxlen, curr_posled_size);

                int pos = symbols_in_curr_posled[ch];
                for (int i = 0; i < curr_posled.size(); ++i)
                {
                    symbols_in_curr_posled[curr_posled[i]] -= (pos + 1);
                }
                curr_posled = curr_posled.substr(pos+1);
            }
            curr_posled += ch;
            symbols_in_curr_posled[ch] = curr_posled.size() - 1;
        }

        int curr_posled_size = curr_posled.size();
        return std::max(maxlen, curr_posled_size);
    }
};


int main()
{
    Solution sol;

    {
        //Example 1:
        //Input: s = "abcabcbb"
        //Output : 3
        //Explanation : The answer is "abc", with the length of 3.
        std::cout << sol.lengthOfLongestSubstring("abcabcbb") << std::endl;
    }



    {
        //    Example 2 :
        //    Input: s = "bbbbb"
        //    Output : 1
        //    Explanation : The answer is "b", with the length of 1.
        std::cout << sol.lengthOfLongestSubstring("bbbbb") << std::endl;
    }
    
    
    {
        //    Example 3 :
        //    Input: s = "pwwkew"
        //    Output : 3
        //    Explanation : The answer is "wke", with the length of 3.
        //    Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
        std::cout << sol.lengthOfLongestSubstring("pwwkew") << std::endl;
    }

    {
        //    Example 3 :
        //    Input: s = "pwwkew"
        //    Output : 3
        //    Explanation : The answer is "wke", with the length of 3.
        //    Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
        std::cout << sol.lengthOfLongestSubstring(" ") << std::endl;
    }


}

#include <iostream>
#include <unordered_map>
#include <vector>


class Solution {
    bool isPalindrome(int index1, int index2, const std::string& str)
    {
        if (index1 > index2)
        {
            return false;
        }

        while (index2 > index1)
        {
            if (str[index1] != str[index2])
            {
                return false;
            }

            ++index1;
            --index2;
        }
        return true;
    }

public:

//    string longestPalindrome(string s) {
    std::string longestPalindrome(const std::string& str)
    {
        if (str == "")
        {
            return str;
        }

        if (str.size() == 1)
        {
            return str;
        }

        std::unordered_map<char, std::vector<int>> includes_symbols;

        for(int i = 0; i < str.size(); ++i)
        {
            includes_symbols[str[i]].push_back(i);
        }

        std::string result(1, str[0]);
        int max_len_polidrom = 1;

        for(int index2 = str.size()-1; index2 >= 0; --index2)
        {
            auto vec = includes_symbols[str[index2]];
            if (vec.size() == 1)
            {
                continue;
            }

            for (auto index1 : vec)
            {
                if (isPalindrome(index1, index2, str))
                {
                    if (index2 - index1 + 1 > max_len_polidrom)
                    {
                        max_len_polidrom = index2 - index1 + 1;
                        result = str.substr(index1, index2 - index1 +1);
                    }
                }
            }
        }
        return result;
    }
};





int main()
{
    Solution sol;

    std::cout << sol.longestPalindrome("babad") << std::endl;    // bab
    std::cout << sol.longestPalindrome("cbbd") << std::endl;     // bb
    std::cout << sol.longestPalindrome("A") << std::endl;        // A
    std::cout << sol.longestPalindrome("aseraweffewafgjh") << std::endl;        // aweffewa
    std::cout << sol.longestPalindrome("ac") << std::endl;        // aweffewa
}

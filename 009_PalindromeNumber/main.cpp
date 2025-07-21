#include <iostream>

class Solution {
public:
    bool isPalindrome(int x)
    {
        if (x < 0)
        {
            return false;
        }

        int x1 = x;
        int y = 0;

        while(x1 > 0)
        {
            if (y > 214748364 )
            {
                return false;
            }

            y *= 10;
            y += x1 % 10;
            x1 /=10;
        }

        if (y == x)
        {
            return true;
        }

        return false;
    }
};


int main()
{
    Solution sol;

    std::cout << sol.isPalindrome(121) << std::endl;
    std::cout << sol.isPalindrome(-121) << std::endl;
    std::cout << sol.isPalindrome(10) << std::endl;
    std::cout << sol.isPalindrome(11) << std::endl;
}

#include <iostream>


class Solution {
public:
    int reverse(int x)
    {
        if (x == -2147483648)
        {
            return 0;
        }
        int result = 0;
        int znak = x < 0 ? -1 : 1;
        x *= znak;
        while (x > 0)
        {
            int ostat = x % 10;
            //2147483647
            if (result > 214748364 || (result == 214748364 && ostat > 7))
            {
                return 0;
            }
            result *=10;
            result += ostat;
            x /= 10;
        }
        return result * znak;
    }
};

using namespace std;

int main()
{
    //2147483647
    //7463847412
    // 964632435
    // 1534236469

    Solution sol;
//    Example 1:
    std::cout << sol.reverse(123) << std::endl;
//  Output: 321
//    Example 2:

    std::cout << sol.reverse(-123) << std::endl;
//  Output: -321
// Example 3:
    std::cout << sol.reverse(120) << std::endl;
// Output: 21
    // Example 4:
    std::cout << sol.reverse(1534236469) << std::endl;
    // Output: 0
}

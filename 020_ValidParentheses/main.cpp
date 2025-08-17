#include <iostream>
#include <string>
#include <stack>

class Solution
{
    public:
            bool isValid(const std::string& str)
            {
                std::stack<char> stck;
                for (const auto ch : str)
                {
                    if (ch == '(')
                    {
                        stck.push(')');
                    }
                    else if (ch == '[')
                    {
                        stck.push(']');
                    }
                    else if (ch == '{')
                    {
                        stck.push('}');
                    }

                    else if (!stck.empty() && ch == stck.top())
                    {
                        stck.pop();
                    }
                    else
                    {
                        return false;
                    }
                }
                return stck.empty();
            }
};




int main()
{
    Solution sol;

    /*

Example 1:

s = "()"

Output: true

Example 2:

s = "()[]{}"

Output: true

Example 3:

s = "(]"

Output: false

Example 4:

s = "([])"

Output: true

Example 5:

s = "([)]"

Output: false
*/



    std::string s;

    s = "()";
    std::cout << s << std::endl;
    std::cout << sol.isValid(s) << std::endl;

//    Output: true

 //   Example 2:

    s = "()[]{}";
    std::cout << s << std::endl;
    std::cout << sol.isValid(s) << std::endl;

 //   Output: true

//    Example 3:

    s = "(]";
    std::cout << s << std::endl;
    std::cout << sol.isValid(s) << std::endl;

//    Output: false

 //   Example 4:

    s = "([])";
    std::cout << s << std::endl;
    std::cout << sol.isValid(s) << std::endl;

//    Output: true

//    Example 5:

    s = "([)]";
    std::cout << s << std::endl;
    std::cout << sol.isValid(s) << std::endl;
//    Output: false





}

#include <iostream>
#include <vector>

class Solution {
public:
    int maxArea(std::vector<int> heigts)
    {
        int left_index = 0;
        int right_index = heigts.size()-1;
        int max_volume = 0;

        while(left_index < right_index)
        {
            int curr_vol = (right_index - left_index) * (heigts[left_index] < heigts[right_index] ? heigts[left_index] : heigts[right_index]);
            max_volume = curr_vol > max_volume ? curr_vol : max_volume;

            if (heigts[right_index] < heigts[left_index])
            {
                --right_index;
            }
            else
            {
                ++left_index;
            }
        }

        return max_volume;
    }
};

int main()
{
    Solution sol;

    std::vector<int> ar1{1,8,6,2,5,4,8,3,7};
    std::cout << sol.maxArea(ar1) << std::endl;

    std::vector<int> ar2{1,1};
    std::cout << sol.maxArea(ar2)  << std::endl;

    std::cout << sol.maxArea({1,2,4,3})  << std::endl;
}



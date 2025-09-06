#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> sortedSquares(std::vector<int>& nums)
    {
        for (size_t i = 0; i < nums.size(); ++i)
        {
            nums[i] = nums[i] * nums[i];
        }

        if (nums.size() < 2)
        {
            return nums;
        }

        int left{0}, right{static_cast<int> (nums.size()-1)}, insert_pos{right};

        std::vector<int> result(nums.size());

        while(left <= right)
        {
            if(nums[right] >= nums[left])
            {
                result[insert_pos] = nums[right];
                --right;
            }
            else
            {
                result[insert_pos] = nums[left];
                ++left;
            }
            --insert_pos;
        }
        return result;
    }
};

int main()
{
    Solution sol;

    {
        std::vector vec{-4, -1, 0, 3, 10};
        auto res = sol.sortedSquares(vec);

        bool is_first = true;
        std::cout << '[';
        for (auto num : res)
        {
            if (!is_first)
            {
                std::cout << ',';
            }
            std::cout << num;
            is_first = false;
        }
        std::cout << ']' << std::endl;
    }

    {
        std::vector vec{-7, -3, 2, 3};
        auto res = sol.sortedSquares(vec);

        bool is_first = true;
        std::cout << '[';
        for (auto num : res)
        {
            if (!is_first)
            {
                std::cout << ',';
            }
            std::cout << num;
            is_first = false;
        }
        std::cout << ']' << std::endl;
    }
    {
        std::vector vec{0, 2};
        auto res = sol.sortedSquares(vec);

        bool is_first = true;
        std::cout << '[';
        for (auto num : res)
        {
            if (!is_first)
            {
                std::cout << ',';
            }
            std::cout << num;
            is_first = false;
        }
        std::cout << ']' << std::endl;
    }
}

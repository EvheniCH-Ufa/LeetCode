#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        if (lists.empty())
        {
            return nullptr;
        }


        bool is_empty = true;
        for(const auto list : lists)
        {
            is_empty = is_empty && (list == nullptr);
            if(!is_empty)
            {
                break;
            }
        }
        if(is_empty)
        {
            return nullptr;
        }

        ListNode *first{nullptr}, *curr{nullptr};

        bool has_not_empty = true;
        while (has_not_empty)
        {
            has_not_empty = false;

            int min_value{99999}, min_index{0};

            for(size_t i = 0; i < lists.size(); ++i)
            {
                if (lists[i] == nullptr)
                {
                    continue;
                }

                has_not_empty = true;
                if (lists[i]->val < min_value)
                {
                    min_index = i;
                    min_value = lists[i]->val;
                }
            }

            if (!has_not_empty)
            {
                break;
            }

            if (first == nullptr)
            {
                curr = lists[min_index];
                first = curr;
            }
            else
            {
                curr->next = lists[min_index];
                curr = curr->next;
            }

            lists[min_index] = lists[min_index]->next;
        }
        return first;
    }
};

int main()
{
    {
        /*
        Example 1:

        Input: lists = [[1,4,5],[1,3,4],[2,6]]
        Output: [1,1,2,3,4,4,5,6]
        Explanation: The linked-lists are:
        [
          1->4->5,
          1->3->4,
          2->6
        ]
        merging them into one sorted linked list:
        1->1->2->3->4->4->5->6
        */

        std::vector<ListNode*> lists(3);

        lists[0] = new ListNode(1);
        lists[0]->next = new ListNode(4);
        lists[0]->next->next = new ListNode(5);

        lists[1] = new ListNode(1);
        lists[1]->next = new ListNode(3);
        lists[1]->next->next = new ListNode(4);

        lists[2] = new ListNode(2);
        lists[2]->next = new ListNode(6);

        Solution sol;

        auto res = sol.mergeKLists(lists);

        bool is_first = true;
        std::cout << '[';
        while (res)
        {
            if (!is_first)
            {
                std::cout << ',';
            }
            std::cout << res->val;
            res = res->next;

            is_first = false;
        }
        std::cout << ']' << std::endl;
    }

    {
        /*
        Example 2:

        Input: lists = []
        Output: []
        */

        std::vector<ListNode*> lists;

        Solution sol;

        auto res = sol.mergeKLists(lists);

        bool is_first = true;
        std::cout << '[';
        while (res)
        {
            if (!is_first)
            {
                std::cout << ',';
            }
            std::cout << res->val;
            res = res->next;

            is_first = false;
        }
        std::cout << ']' << std::endl;
    }

    {
        /*
    Example 3:

    Input: lists = [[]]
    Output: []

    */

        std::vector<ListNode*> lists(1);

        Solution sol;

        auto res = sol.mergeKLists(lists);

        bool is_first = true;
        std::cout << '[';
        while (res)
        {
            if (!is_first)
            {
                std::cout << ',';
            }
            std::cout << res->val;
            res = res->next;

            is_first = false;
        }
        std::cout << ']' << std::endl;
    }








}

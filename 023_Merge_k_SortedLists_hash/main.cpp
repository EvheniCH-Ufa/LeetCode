#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>

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

        std::set<int> values;
        std::unordered_map<int, std::vector<ListNode*>> ptr_hash;

        for(size_t i = 0; i < lists.size(); ++i)
        {
            auto curr = lists[i];
            while(curr != nullptr)
            {
                values.insert(curr->val);
                ptr_hash[curr->val].push_back(curr);
                curr = curr->next;
            }
        }

        ListNode *first{nullptr}, *curr{nullptr};
        for (int curr_value : values)
        {
            auto ptr_vec = ptr_hash.find(curr_value)->second;
            for(const auto ptr : ptr_vec)
            {
                if (first == nullptr)
                {
                    curr = ptr;
                    first = curr;
                }
                else
                {
                    curr->next = ptr;
                    curr = curr->next;
                }
            }
        }
        curr->next = nullptr;
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

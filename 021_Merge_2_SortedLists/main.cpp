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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
    {
        if (list1 == nullptr)
        {
            return list2;
        }

        if (list2 == nullptr)
        {
            return list1;
        }


        auto curr1 = list1;
        auto curr2 = list2;

        ListNode *first{nullptr};
        if(curr2->val < curr1->val)
        {
            first = curr2;
            curr2 = curr2->next;
        }
        else
        {
            first = curr1;
            curr1 = curr1->next;
        }

        auto curr = first;


        while(true)
        {
            if (curr1 == nullptr)
            {
                curr->next = curr2;
                break;
            }

            if (curr2 == nullptr)
            {
                curr->next = curr1;
                break;
            }

            if(curr2->val < curr1->val)
            {
                curr->next = curr2;
                curr2 = curr2->next;
            }
            else
            {
                curr->next = curr1;
                curr1 = curr1->next;
            }
            curr = curr->next;
        }
        //curr->next = nullptr;
        return first;
    }
};

int main()
{

    {
        /*
        Example 1:

        Input: list1 = [1,2,4], list2 = [1,3,4]
        Output: [1,1,2,3,4,4]
        */

        std::vector<ListNode*> lists(2);

        lists[0] = new ListNode(1);
        lists[0]->next = new ListNode(2);
        lists[0]->next->next = new ListNode(4);

        lists[1] = new ListNode(1);
        lists[1]->next = new ListNode(3);
        lists[1]->next->next = new ListNode(4);

        Solution sol;

        auto res = sol.mergeTwoLists(lists[0], lists[1]);

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

        Input: list1 = [], list2 = []
        Output: []
        */

        std::vector<ListNode*> lists(2);

        Solution sol;

        auto res = sol.mergeTwoLists(lists[0], lists[1]);

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

    Input: list1 = [], list2 = [0]
    Output: [0]
    */

        std::vector<ListNode*> lists(2);
        lists[1] = new ListNode(0);

        Solution sol;

        auto res = sol.mergeTwoLists(lists[0], lists[1]);

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

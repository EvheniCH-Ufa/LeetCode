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
    ListNode* removeNthFromEnd(ListNode* lst, int target)
    {
        if (lst == nullptr)
        {
            return nullptr;
        }

        if (lst->next == nullptr && target == 1)
        {
            return nullptr;
        }

        int x = 0;
        ListNode* res = RemoveNodeRec(lst, target, x);
        if (target == x)
        {
            ListNode* tmp = res;
            res = res->next;
            delete tmp;
        }
        return res;
    }


    ListNode* RemoveNodeRec(ListNode* lst, int target, int& next_num)
    {
        if(lst->next == nullptr)
        {
            next_num = 1;
            return lst;
        }

        ListNode* next = RemoveNodeRec(lst->next, target, next_num);
        if (next_num == target)
        {
            ListNode* tmp = next->next;
            delete next;
            lst->next = tmp;
            next_num = -555;

            return lst;
        }
        ++next_num;
        return lst;
    }
};

int main()
{
    Solution sol;

    {
        ListNode* list;
        list = new ListNode(1);
        list->next = new ListNode(2);
        list->next->next = new ListNode(3);
        list->next->next->next = new ListNode(4);
        list->next->next->next->next = new ListNode(5);

        auto res = sol.removeNthFromEnd(list, 5);

        bool is_first = true;
        std::cout << '[';
        ListNode* tmp = res;
        while (tmp)
        {
            if (!is_first)
            {
                std::cout << ',';
            }
            std::cout << tmp->val;
            tmp = tmp->next;

            is_first = false;
        }
        std::cout << ']' << std::endl;

        while (res != nullptr)
        {
            tmp = res;
            res = res->next;
            delete tmp;
        }
    }

    {
        ListNode* list;
        list = new ListNode(1);


        auto res = sol.RemoveNode(list, 1);

        bool is_first = true;
        std::cout << '[';
        ListNode* tmp = res;
        while (tmp)
        {
            if (!is_first)
            {
                std::cout << ',';
            }
            std::cout << tmp->val;
            tmp = tmp->next;

            is_first = false;
        }
        std::cout << ']' << std::endl;

        while (res != nullptr)
        {
            tmp = res;
            res = res->next;
            delete tmp;
        }
    }

    {
        ListNode* list = nullptr;

        auto res = sol.RemoveNode(list, 1);

        bool is_first = true;
        std::cout << '[';
        ListNode* tmp = res;
        while (tmp)
        {
            if (!is_first)
            {
                std::cout << ',';
            }
            std::cout << tmp->val;
            tmp = tmp->next;

            is_first = false;
        }
        std::cout << ']' << std::endl;

        while (res != nullptr)
        {
            tmp = res;
            res = res->next;
            delete tmp;
        }
    }
}

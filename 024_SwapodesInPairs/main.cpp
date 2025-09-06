#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* lst)
    {
        if(lst == nullptr || lst->next == nullptr)
        {
            return lst;
        }


        ListNode *root = lst->next;
        ListNode *tmp = lst->next->next;
        lst->next->next = lst;
        lst->next = tmp;

        ListNode *prev = root->next;
        ListNode *curr = tmp;
        while (curr != nullptr && curr->next != nullptr)
        {
            prev->next = curr->next;
            curr->next = curr->next->next;
            prev->next->next = curr;

            prev = curr;
            curr = curr->next;
        }

        return root;
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
       // list->next->next->next->next = new ListNode(5);

        auto res = sol.swapPairs(list);

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
        list->next = new ListNode(2);
        list->next->next = new ListNode(3);
        list->next->next->next = new ListNode(4);
        list->next->next->next->next = new ListNode(5);

        auto res = sol.swapPairs(list);

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


        auto res = sol.swapPairs(list);

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

        auto res = sol.swapPairs(list);

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

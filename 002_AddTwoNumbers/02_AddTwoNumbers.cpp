// 02_AddTwoNumbers.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;

        auto curr_first_ptr = l1;
        auto curr_second_ptr = l2;

        int perenos = 0;
        int nomer_kruga = 0;
        while (curr_first_ptr || curr_second_ptr)
        {
            ++nomer_kruga;

            int val = perenos + ((curr_first_ptr) ? curr_first_ptr->val : 0) + ((curr_second_ptr) ? curr_second_ptr->val : 0);

            curr_first_ptr->val = val % 10 ;
            perenos = val / 10;


            if (!curr_first_ptr->next && !curr_second_ptr)
            {
                break;
            }


            if (!curr_first_ptr->next && !curr_second_ptr->next)
            {
                break;
            }

            if ((curr_first_ptr->next && !curr_second_ptr)
                || (curr_first_ptr->next && curr_second_ptr && !(curr_second_ptr->next)))
            {
                curr_first_ptr = curr_first_ptr->next;
                curr_second_ptr = nullptr;
                continue;
            }

            if (curr_first_ptr->next && curr_second_ptr->next)
            {
                curr_first_ptr = curr_first_ptr->next;
                curr_second_ptr = curr_second_ptr->next;
                continue;
            }

            if (!curr_first_ptr->next && curr_second_ptr->next) // first-next == null   and   second-next != null
            {
                curr_first_ptr->next = curr_second_ptr->next;
                curr_first_ptr = curr_first_ptr->next;
                curr_second_ptr = nullptr;
                continue;
            }

        }

        if (perenos)
        {
            curr_first_ptr->next = new ListNode(perenos);
        }
        return l1;
    }
};

int main()
{
    {
        ListNode* l1 = new ListNode(2);
        l1->next = new ListNode(4);
        l1->next->next = new ListNode(3);

        ListNode* l2 = new ListNode(5);
        l2->next = new ListNode(6);
        l2->next->next = new ListNode(4);

        Solution sol;

        auto res = sol.addTwoNumbers(l1, l2);
        while (res)
        {
            std::cout << res->val;
            res = res->next;
        }
        std::cout << std::endl;

        /*
        Input: l1 = [2, 4, 3],
               l2 = [5, 6, 4]
        Output    : [7, 0, 8]
        Explanation : 342 + 465 = 807.
        */
    }

    {
        ListNode* l1 = new ListNode(0);

        ListNode* l2 = new ListNode(0);

        Solution sol;

        auto res = sol.addTwoNumbers(l1, l2);
        while (res)
        {
            std::cout << res->val;
            res = res->next;
        }
        std::cout << std::endl;

        /*
    Input : l1 = [0], l2 = [0]
    Output : [0]
    Example 3 :
        */
    }

    {
        ListNode* l1 = new ListNode(9);
        auto c_l1 = l1;

        c_l1->next = new ListNode(9);
        c_l1 = c_l1->next;

        c_l1->next = new ListNode(9);
        c_l1 = c_l1->next;

        c_l1->next = new ListNode(9);
        c_l1 = c_l1->next;

        c_l1->next = new ListNode(9);
        c_l1 = c_l1->next;

        c_l1->next = new ListNode(9);
        c_l1 = c_l1->next;

        c_l1->next = new ListNode(9);


        ListNode* l2 = new ListNode(9);
        auto c_l2 = l2;
        c_l2->next = new ListNode(9);
        c_l2 = c_l2->next;
        c_l2->next = new ListNode(9);
        c_l2 = c_l2->next;
        c_l2->next = new ListNode(9);

        Solution sol;

        auto res = sol.addTwoNumbers(l1, l2);
        while (res)
        {
            std::cout << res->val;
            res = res->next;
        }
        std::cout << std::endl;

        /*
    Input : l1 = [9, 9, 9, 9, 9, 9, 9],
            l2 = [9, 9, 9, 9]
    Output     : [8, 9, 9, 9, 0, 0, 0, 1]
        */
    }

    {
        ListNode* l1 = new ListNode(2);
        l1->next = new ListNode(4);
        l1->next->next = new ListNode(9);

        ListNode* l2 = new ListNode(5);
        l2->next = new ListNode(6);
        l2->next->next = new ListNode(4);
        l2->next->next->next = new ListNode(9);

        Solution sol;

        auto res = sol.addTwoNumbers(l1, l2);
        while (res)
        {
            std::cout << res->val;
            res = res->next;
        }
        std::cout << std::endl;

        /*
        Input: l1 = [2, 4, 3],
               l2 = [5, 6, 4, 9]
        Output    : [7, 0, 4, 0, 1]
        */
    }



}

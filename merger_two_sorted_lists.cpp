// 21. Merge Two Sorted Lists
// Link: https://leetcode.com/problems/merge-two-sorted-lists

#include <iostream>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *new_list = nullptr;
        ListNode *it1 = nullptr;
        ListNode *it2 = nullptr;

        if (list1 == nullptr)
        {
            return list2;
        }
        else if (list2 == nullptr)
        {
            return list1;
        }

        if (list1->val <= list2->val)
        {
            new_list = list1;
            it1 = list1->next;
            it2 = list2;
        }
        else
        {
            new_list = list2;
            it2 = list2->next;
            it1 = list1;
        }

        ListNode *new_list_it = new_list;
        while (true)
        {
            if (it1 == nullptr && it2 == nullptr)
            {
                break;
            }
            else if (it1 != nullptr && it2 == nullptr)
            {
                new_list_it->next = it1;
                new_list_it = new_list_it->next;
                it1 = it1->next;
            }
            else if (it1 == nullptr && it2 != nullptr)
            {
                new_list_it->next = it2;
                new_list_it = new_list_it->next;
                it2 = it2->next;
            }
            else if (it1->val <= it2->val)
            {
                new_list_it->next = it1;
                new_list_it = new_list_it->next;
                it1 = it1->next;
            }
            else
            {
                new_list_it->next = it2;
                new_list_it = new_list_it->next;
                it2 = it2->next;
            }
        }

        return new_list;
    }
};
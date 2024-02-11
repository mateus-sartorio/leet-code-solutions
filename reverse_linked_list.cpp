// 206. Reverse Linked List
// Link: https://leetcode.com/problems/reverse-linked-list

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
    ListNode *reverseList(ListNode *head)
    {
        ListNode *back_pointer = head;
        if (back_pointer == nullptr)
        {
            return head;
        }

        ListNode *middle_pointer = head->next;
        if (middle_pointer == nullptr)
        {
            return head;
        }

        ListNode *front_pointer = head->next->next;
        if (front_pointer == nullptr)
        {
            middle_pointer->next = back_pointer;
            back_pointer->next = nullptr;
            return middle_pointer;
        }

        back_pointer->next = nullptr;
        while (true)
        {
            middle_pointer->next = back_pointer;
            back_pointer = middle_pointer;
            middle_pointer = front_pointer;
            front_pointer = front_pointer->next;

            if (front_pointer == nullptr)
            {
                middle_pointer->next = back_pointer;
                return middle_pointer;
            }
        }
    }
};
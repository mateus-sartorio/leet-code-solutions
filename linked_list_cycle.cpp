// 141. Linked List Cycle
// Link: https://leetcode.com/problems/linked-list-cycle

#include <iostream>
#include <unordered_set>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        unordered_set<ListNode *> has_been_found;

        ListNode *it = head;
        while (it)
        {
            if (has_been_found.contains(it))
            {
                return true;
            }

            has_been_found.insert(it);
            it = it->next;
        }

        return false;
    }
};
// 141. Linked List Cycle
// Link: https://leetcode.com/problems/linked-list-cycle

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
    bool hasCycle(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;

        if (!head)
        {
            return false;
        }

        while (slow->next)
        {
            slow = slow->next;
            if (!slow)
            {
                return false;
            }

            if (fast->next)
            {
                fast = fast->next;
                if (!fast)
                {
                    return false;
                }
            }
            else
            {
                return false;
            }

            if (fast->next)
            {
                fast = fast->next;
                if (!fast)
                {
                    return false;
                }
            }
            else
            {
                return false;
            }

            if (slow == fast)
            {
                return true;
            }
        }

        return false;
    }
};
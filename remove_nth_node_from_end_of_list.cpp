// 19. Remove Nth Node From End of List
// Link: https://leetcode.com/problems/remove-nth-node-from-end-of-list

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
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = 0;

        ListNode* it = head;
        while(it) {
            size++;
            it = it->next;
        }

        int index = size - n;

        if(index == 0) {
            return head->next;
        }

        if(index == 1) {
            head->next = head->next->next;
            return head;
        }

        it = head;
        for(int i = 0; i < size - n - 1; i++) {
            it = it->next;
        }

        cout << it->val << endl;

        if(!it->next) {
            return nullptr;
        }
        
        it->next = it->next->next;

        return head;
    }
};

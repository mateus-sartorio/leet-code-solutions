// 2. Add Two Numbers
// Link: https://leetcode.com/problems/add-two-number

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* outputList = nullptr;
        ListNode* listNodeIt = outputList;

        ListNode* it1 = l1;
        ListNode* it2 = l2;

        int currentDigit = 0;
        int carry = 0;
        while(it1 || it2) {
            int currentSum = (it1 ? it1->val : 0) + (it2 ? it2->val : 0) + carry;
            
            currentDigit = (currentSum) % 10;
            carry = (currentSum) / 10;

            if(!outputList) {
                outputList = new ListNode(currentDigit, nullptr);
                listNodeIt = outputList;
            }
            else {
                listNodeIt->next = new ListNode(currentDigit, nullptr);
                listNodeIt = listNodeIt->next;
            }

            if(it1) {
                it1 = it1->next;
            }

            if(it2) {
                it2 = it2->next;
            }
        }

        if(carry) {
            listNodeIt->next = new ListNode(carry, nullptr);
        }

        return outputList;
    }
};

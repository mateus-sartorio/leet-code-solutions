// 134. Reorder List
// Link: https://leetcode.com/problems/reorder-list

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

int current(int size, int i)
{
    if ((i % 2) == 0)
    {
        return i / 2;
    }
    else
    {
        return size - (i / 2) - 1;
    }
}

class Solution
{
public:
    void reorderList(ListNode *head)
    {
        unordered_map<int, ListNode *> map;
        int n = 0;

        ListNode *i = head;
        while (i->next)
        {
            map[n] = i;
            n++;
            i = i->next;
        }
        n++;
        map[n - 1] = i;

        cout << n << endl;
        cout << map[n - 1]->val << endl;

        i = head;
        for (int j = 0; j < n; j++)
        {
            if (j < n - 1)
            {
                i->next = map[current(n, j + 1)];
            }
            else
            {
                i->next = nullptr;
                break;
            }
            i = i->next;
        }
    }
};

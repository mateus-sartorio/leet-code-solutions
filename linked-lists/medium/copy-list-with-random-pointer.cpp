// 138. Copy List With Random Pointer
// Link: https://leetcode.com/problems/copy-list-with-random-pointer

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* copyHead = nullptr;
        Node* copyIt = copyHead;

        unordered_map<Node*, int> addressIndexMap;

        Node* it = head;
        int i = 0;
        while(it) {
            addressIndexMap[it] = i;

            it = it->next;
            i++;
        }

        unordered_map<int, Node*> newListIndexAddressMap;

        it = head;
        i = 0;
        while(it) {
            if(!copyIt) {
                copyHead = new Node(it->val);
                copyIt = copyHead;
            }
            else {
                copyIt->next = new Node(it->val);
                copyIt = copyIt->next;
            }

            newListIndexAddressMap[i] = copyIt;

            it = it->next;
            i++;
        }

        it = head;
        copyIt = copyHead;
        i = 0;
        while(copyIt) {
            if(!it->random) {
                copyIt->random = nullptr;
            }
            else {
                int index = addressIndexMap[it->random];
                Node* newNodeRandomAddress = newListIndexAddressMap[index];
                copyIt->random = newNodeRandomAddress;
            }
            
            copyIt = copyIt->next;
            it = it->next;
            i++;
        }

        return copyHead;
    }
};

// 226. Invert Binary Tree
// Link: https://leetcode.com/problems/invert-binary-tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    void invertTreeRecursive(TreeNode* node) {
        if(node == nullptr) {
            return;
        }

        TreeNode* leftNode = node->left;
        TreeNode* rightNode = node->right;

        node->left = rightNode;
        node->right = leftNode;

        if(node->left) {
            invertTreeRecursive(node->left);
        }
        if(node->right) {
            invertTreeRecursive(node->right);
        }
    }

public:
    TreeNode* invertTree(TreeNode* root) {
        invertTreeRecursive(root);
        return root;
    }
};

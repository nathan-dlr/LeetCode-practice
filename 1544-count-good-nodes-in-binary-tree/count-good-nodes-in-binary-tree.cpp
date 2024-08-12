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
public:
    int countGoodNodes(TreeNode* root, int val) {
        if (root == nullptr) {
            return 0;
        }
        int goodNode = 0;
        int next_val = val;
        if (root->val >= val) {
            goodNode = 1;
            next_val = root->val;
        }
        int leftGoodNodes = countGoodNodes(root->left, next_val);
        int rightGoodNodes = countGoodNodes(root->right, next_val);
        return goodNode + leftGoodNodes + rightGoodNodes;
    }
    int goodNodes(TreeNode* root) {
        return 1 + countGoodNodes(root->left, root->val) + countGoodNodes(root->right, root->val);
    }
};
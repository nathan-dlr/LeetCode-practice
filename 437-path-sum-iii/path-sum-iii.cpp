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
    int count = 0;
    void NodePathSum(TreeNode* root, int targetSum, long curr_sum = 0) {
        if (root == nullptr) {
            return;
        }
        curr_sum += root->val;
        if (curr_sum == targetSum) {
            count++;
        }
        NodePathSum(root->left, targetSum, curr_sum);
        NodePathSum(root->right, targetSum, curr_sum);
        return;
    }

    int pathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) {
            return count;
        }
        NodePathSum(root, targetSum);
        pathSum(root->left, targetSum);
        pathSum(root->right, targetSum);
        return count;
    }
};
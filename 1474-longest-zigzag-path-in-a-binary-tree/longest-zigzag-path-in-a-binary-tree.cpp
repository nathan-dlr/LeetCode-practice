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
    int max = 0;
    void findDepth(TreeNode* root, int dir, int count = 0) {
        if (root == nullptr) {
            count--;
            max = count > max ? count : max;
            return;
        }
        count++;
        if (dir) {
            findDepth(root->right, 0, count);
        }
        else {
            findDepth(root->left, 1, count);
        }
    }
    int longestZigZag(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        findDepth(root, 0);
        findDepth(root, 1);
        longestZigZag(root->left);
        longestZigZag(root->right);
        return max;

    }
};
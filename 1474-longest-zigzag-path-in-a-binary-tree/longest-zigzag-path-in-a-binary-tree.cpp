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
    void leftZag(TreeNode* root, int count = 0) {
        if (root == nullptr) {
            count--;
            max = count > max ? count : max;
            return;
        }
        count++;
        rightZag(root->right, count);
    }
    void rightZag(TreeNode* root, int count = 0) {
        if (root == nullptr) {
            count--;
            max = count > max ? count : max;
            return;
        }
        count++;
        leftZag(root->left, count);
    }
    int longestZigZag(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        leftZag(root);
        rightZag(root);
        longestZigZag(root->left);
        longestZigZag(root->right);
        return max;

    }
};
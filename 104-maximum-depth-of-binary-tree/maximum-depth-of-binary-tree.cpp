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
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {return 0;}
        int right_depth = 0;
        int left_depth = 0;
        if (root->left == nullptr && root->right == nullptr) {
            return 1;
        }
        if (root->left) {
            right_depth = 1 + maxDepth(root->left);
        }
        
        if (root->right) {
            left_depth = 1 + maxDepth(root->right);
        }
        if (right_depth > left_depth) {
            return right_depth;
        }
        else {
            return left_depth;
        }

    }
};
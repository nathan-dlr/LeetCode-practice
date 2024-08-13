/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* search_left;
        TreeNode* search_right;
        if (!root) {
            return nullptr;
        }
        if (root == p || root == q) {
            return root;
        }
        else {
            search_left = lowestCommonAncestor(root->left, p, q);
            search_right = lowestCommonAncestor(root->right, p, q);
            if (search_left && search_right) {
                return root;
            }
            else {
                if (search_left) {
                    return search_left;
                }
                else {
                    return search_right;
                }
            }
        }
    }
};
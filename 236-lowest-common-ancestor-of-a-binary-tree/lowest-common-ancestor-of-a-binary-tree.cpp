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
    bool searchSide(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) {
            return false;
        }
        else {
            if (root == p || root == q) {
                return true;
            }
        }
        if (searchSide(root->left, p, q) || searchSide(root->right, p, q)) {
            return true;
        }
        return false;
        
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        bool search_left;
        bool search_right;
        if (root == p || root == q) {
            return root;
        }
        else {
            search_left = searchSide(root->left, p, q);
            search_right = searchSide(root->right, p, q);
            if ((search_left && search_right) || ((search_left || search_right) && (root == p || root==q))) {
                return root;
            }

        }
        if (search_left && !search_right) {
            return lowestCommonAncestor(root->left, p, q);
        }
        else {
            return lowestCommonAncestor(root->right, p, q);
        }
    }
};
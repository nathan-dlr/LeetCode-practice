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
    bool valid(TreeNode* curr, long min, long max) {
        bool left = false;
        bool right = false;
        if (min < curr->val && curr->val < max) {
            left = curr->left ? valid(curr->left, min, curr->val) : true;
            right = left && curr->right ? right = valid(curr->right, curr->val, max) : true;
        }
        return (left && right);
    }
    bool isValidBST(TreeNode* root) {  
        return valid(root, std::numeric_limits<long>::min(), std::numeric_limits<long>::max());        
    }
};
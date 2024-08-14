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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> RSV;
        if (root == nullptr) {return RSV;}
        queue<TreeNode*> nodes;
        nodes.emplace(root);
        TreeNode* RS;
        int size;
        while (!nodes.empty()) {
            size = nodes.size();
            for (int i = 0; i < size; i++) {
                RS = nodes.front();
                nodes.pop();
                if (RS->left) {
                    nodes.emplace(RS->left);
                }
                if (RS->right) {
                    nodes.emplace(RS->right);
                }
            }
            RSV.push_back(RS->val);
        }
        return RSV;
    }
    
};
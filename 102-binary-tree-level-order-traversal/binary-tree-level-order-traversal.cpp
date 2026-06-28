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
    vector<vector<int>> levelOrder(TreeNode* root) {
        std::vector<std::vector<int>> lvlOrder;
        std::queue<TreeNode*> lvl;
        if (root) lvl.push(root);
  
        while (!lvl.empty()) {
            lvlOrder.push_back({});
            int size = lvl.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = lvl.front();
                lvl.pop();
                
                if (node->left) lvl.push(node->left);
                if (node->right) lvl.push(node->right);
                
                lvlOrder.back().push_back(node->val);
            }
        }
        return lvlOrder;
    }
};
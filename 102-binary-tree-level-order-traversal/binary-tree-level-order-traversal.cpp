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
        std::queue<TreeNode*> currLvl;
        std::queue<TreeNode*> nextLvl;
        if (root) nextLvl.push(root);
        
        while (!nextLvl.empty()) {
            std::swap(currLvl, nextLvl);
            lvlOrder.push_back({});
            
            while (!currLvl.empty()) {
                TreeNode* node = currLvl.front();
                currLvl.pop();
              
                if (node->left) nextLvl.push(node->left);
                if (node->right) nextLvl.push(node->right);
                
                lvlOrder.back().push_back(node->val);
            }
        }
        return lvlOrder;
    }
};
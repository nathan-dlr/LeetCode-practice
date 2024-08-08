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
    vector<int> getLeafs(TreeNode* root) {
        vector<int> leafs;
        if (root->left == nullptr && root->right == nullptr) {
            leafs.push_back(root->val);
            return leafs;
        }
        vector<int> children_leafs;
        if (root->left) {
            children_leafs = getLeafs(root->left);
            leafs.insert(leafs.end(), children_leafs.begin(), children_leafs.end());
        }
        if (root->right) {
            children_leafs = getLeafs(root->right);
            leafs.insert(leafs.end(), children_leafs.begin(), children_leafs.end());
        }
        return leafs;

    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leafs1;
        vector<int> leafs2;
        leafs1 = getLeafs(root1);
        leafs2 = getLeafs(root2);
        if (leafs1.size() != leafs2.size()) {
            return false;
        }
        for (int i = 0; i < leafs1.size(); i++) {
            if (leafs1[i] != leafs2[i]) {
                return false;
            }
        }
        return true;
        
    }
};
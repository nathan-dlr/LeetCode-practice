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
    int maxLevelSum(TreeNode* root) {
        int sum = 0;
        int max_sum;
        int size;
        int level = 1;
        int max_level = 1;
        TreeNode* curr_node;
        queue<TreeNode*> nodes;
        nodes.emplace(root);

        while (!nodes.empty()) {
            size = nodes.size();
            for (int i = 0; i < size; i++) {
                curr_node = nodes.front();
                sum += curr_node->val;
                nodes.pop();
                if (curr_node->left) {
                    nodes.emplace(curr_node->left);
                }
                if (curr_node->right) {
                    nodes.emplace(curr_node->right);
                }
            }
            if (sum > max_sum || level == 1) {
                max_sum = sum;
                max_level = level;
            }
            sum = 0;
            level++;
        }
        return max_level;
    }
};
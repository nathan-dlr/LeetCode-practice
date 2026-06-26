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
    bool findNode(TreeNode* root, std::stack<TreeNode*>& path, int nodeVal) {
        if (!root) {
            return false;
        }

        path.push(root);
        if (root->val == nodeVal) {
            return true;
        }

        if (findNode(root->right, path, nodeVal)) {
            return true;
        }
        if (findNode(root->left, path, nodeVal)) {
            return true;
        }
        path.pop();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Using dfs with a stack can gives us a history of the direct path to a node
        // Use two stacks to store the history of each
        std::stack<TreeNode*> pathP;
        std::stack<TreeNode*> pathQ;
        findNode(root, pathP, p->val);
        findNode(root, pathQ, q->val);

        // The size of the stack indicates the level of the node
        std::stack<TreeNode*>& longerPath = pathP.size() > pathQ.size() ? pathP : pathQ;
        std::stack<TreeNode*>& shorterPath = longerPath == pathP ? pathQ : pathP;

        // Level both stacks
        while (longerPath.size() != shorterPath.size()) {
            longerPath.pop();
        }

        // Observe the path taken at each level, until the path intersects
        while (!longerPath.empty()) {
            if (longerPath.top() == shorterPath.top()) {
                return longerPath.top();
            }
            longerPath.pop();
            shorterPath.pop();
        }
        return nullptr;
    }
};
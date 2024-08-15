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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) {return root;}
        TreeNode* parent = root;
        TreeNode* return_node = root;
        while (root != nullptr) {
            if (root->val > key) {
                parent = root;
                root = root->left;
            }
            else if (root->val < key) {
                parent = root;
                root = root->right;
            }
            else {
                TreeNode* delete_node = root;
                //where is node we need to delete in relation to its parent
                bool left = false;
                if (parent->val > delete_node->val) {
                    left = true;
                }
                //two children
                if (delete_node->left && delete_node->right) {
                    TreeNode* sub_parent_max = root;
                    TreeNode* sub_parent_curr = root;
                    root = root->left;
                    TreeNode* replacement = root;
                    // find replacement node, largest node on left;
                    while (root->left != nullptr || root->right != nullptr) {
                        sub_parent_curr = root;
                        if (root->right) {
                            root = root->right;
                        }
                        else {
                            root = root->left;
                        }
                        if (replacement->val < root->val) {
                            sub_parent_max = sub_parent_curr;
                            replacement = root;
                        }
                    }
                    //remove replacement node
                    if (sub_parent_max->left == replacement) {
                        if (replacement->left) {
                            sub_parent_max->left = replacement->left;
                        }
                        else {
                            sub_parent_max->left = nullptr;
                        }
                    }
                    else {
                        if (replacement->left) {
                            sub_parent_max->right = replacement->left;
                        }
                        else {
                            sub_parent_max->right = nullptr;
                        }
                    }
                    //insert replacement node
                    if (parent != delete_node) {
                        if (left) {
                            parent->left = replacement;
                        }
                        else {
                            parent->right = replacement;
                        }
                    }
                    if (delete_node->left && delete_node->left != replacement) {
                        replacement->left = delete_node->left;
                    }
                    if (delete_node->right && delete_node->right != replacement) {
                        replacement->right = delete_node->right;
                    }
                    if (parent == delete_node) {
                        return_node = replacement;
                    }                    
                }
                //one child
                else if (root->left && !(root->right)) {
                    if (parent == root) {
                        root = root->left;
                        return_node = root;
                    }
                    else if (left) {
                        parent->left = root->left;
                    }
                    else {
                        parent->right = root->left;
                    }
                }
                else if (root->right && !(root->left)) {
                    if (parent == root) {
                        root = root->right;
                        return_node = root;
                    }
                    else if (left) {
                        parent->left = root->right;
                    }
                    else {
                        parent->right = root->right;
                    }
                }
                else {
                //no children
                    if (parent == root) {
                        return nullptr;
                    }
                    else {
                        if (left) {
                            parent->left = nullptr;
                        }
                        else {
                            parent->right = nullptr;
                        }
                    }
                }
                break;
            }
        }
        return return_node;
    }
};
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
        if(root == nullptr) return root;
        if (root->val == key) {
            if(root->right == nullptr) {
                return root->left;
            }  
            if(root->left == nullptr) {
                return root->right;
            }  
                TreeNode* r = root->right;
                while (r->left != nullptr) {
                    r = r->left;
                }
                //后继节点为r
                root->right = deleteNode(root->right, r->val);
                root->val = r->val;
                return root;
            
        } 
        if(root->val > key) {
            root->left = deleteNode(root->left, key);
        } else {
            root->right = deleteNode(root->right, key);
        }
        return root;
    }
};
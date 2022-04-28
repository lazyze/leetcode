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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        //找到这个节点，logN
        
        if(p->right != NULL) {
            TreeNode* tmp = p->right;
            while (tmp->left != NULL) {
                tmp = tmp->left;
            }
            return tmp;
        } else {
            TreeNode* ans = NULL;
            while (root != NULL && root != p) {
                if (root->val < p->val) {
                    root = root->right;
                } else {
                    if(ans == NULL || root->val < ans->val) {
                        ans = root;
                    }
                    root = root->left;
                }
            }
            return ans;
        }
        
    }
};
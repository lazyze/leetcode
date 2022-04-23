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
    vector<int> inorderTraversal(TreeNode* root) {
        recursive(root);
        return ans;
    }

    void recursive(TreeNode* root) {
        if (root == nullptr) return;
        recursive(root->left);
        ans.push_back(root->val);
        recursive(root->right);
    }
    vector<int> ans;
};
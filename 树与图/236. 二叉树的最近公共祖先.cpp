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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        pre = root;
        recursive(root);
        while (p != root) {
            visit.insert(p);
            p = fa[p->val];
        }
        visit.insert(p);
        while (visit.find(q) == visit.end()) {
            q = fa[q->val];
        }
        return q;
    }

    void recursive(TreeNode *root) {
        if(root == NULL) {
            return;
        }
        fa[root->val] = pre;
        pre = root;
        recursive(root->left);
        pre = root;
        recursive(root->right);
        return;
    }
    TreeNode* pre;
    unordered_map<int, TreeNode*> fa;
    unordered_set<TreeNode*> visit;
};
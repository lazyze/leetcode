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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        this->preorder = preorder;
        this->inorder = inorder;
        int n = preorder.size() - 1;
        return cal(0, n, 0, n);
    }
    //[a...b]前序
    //[c...d]中序
    TreeNode* cal(int a, int b, int c, int d) {
        if(a > b) return nullptr;
        TreeNode* ans = new TreeNode;
        ans->val = preorder[a];
        if (a == b) {
            return ans;
        }
        int tmp = c;
        while (tmp <= d) {
            if (inorder[tmp] == preorder[a])break;
            tmp++;
        }
        int num = tmp - 1 - c + 1;
        int end = num + a;
        ans->left = cal(a + 1, num + a,c, tmp - 1);
        ans->right = cal(num + a + 1,b,tmp + 1, d);
        return ans;   
    }

    vector<int> preorder;
    vector<int> inorder;
};

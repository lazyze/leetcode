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
    bool isValidBST(TreeNode* root) {
        flag = true;
        recursive(root);
        return flag;
    }

    void recursive(TreeNode* root) {
        if(root == nullptr || (root->left == nullptr && root->right == nullptr)) {
            return ;
        }
        long lmax = LONG_MIN;
        long rmin = LONG_MAX;
        if(root->right != nullptr)rmin = getmin(root->right);
        if(root->left != nullptr)lmax = getmax(root->left);
        if (root->val >= rmin || root->val <= lmax) {
            flag = false;
            return ;
        }
        recursive(root->left);
        recursive(root->right);
    }

    int getmin(TreeNode* root) {
        while(root->left) {
            root = root->left;
        }
        return root->val;
    }

    int getmax(TreeNode* root) {
        while(root->right) {
            root = root->right;
        }
        return root->val;
    }
    bool flag;
};



// class Solution {
// public:

// struct info{
//         long minv;
//         long maxv;
//         bool flag;
//     };

//     bool isValidBST(TreeNode* root) {
//         return recursive(root)->flag;
//     }

//     info* recursive(TreeNode* root) {
//         info* tmp = new info;
//         if(root == nullptr) {
//             tmp->maxv = INT_MIN - 1l;
//             tmp->minv = INT_MAX + 1l;
//             tmp->flag = true;
//             return tmp;
//         }
//         info* l = recursive(root->left);
//         info* r = recursive(root->right);
//         tmp->flag = l->flag && r->flag && (l->maxv < root->val) && (root->val < r->minv);
//         tmp->maxv = max(long(root->val), max(l->maxv, r->maxv));
//         tmp->minv = min(long(root->val), min(l->minv, r->minv));
//         return tmp;
//     }

    
// };
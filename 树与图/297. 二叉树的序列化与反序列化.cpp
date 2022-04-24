/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == NULL) return "null";
        string l = serialize(root->left);
        string r = serialize(root->right);
        string ans = to_string(root->val) + "," + l + "," + r;
        return ans;
    }

    //1,2,null,null,3,4,null,null,5,null,null
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        solve(data);
        cur = 0;
        return cal();
    }

    TreeNode* cal() {
        if (vec[cur] == "null") {
            cur++;
            return NULL;
        }
        TreeNode* ans = new TreeNode;
        ans->val = stoi(vec[cur]);
        cur++;
        ans->left = cal();
        ans->right = cal();
        return ans;
    }

    void solve(string& str) {
        int first = 0;
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == ',') {
                vec.push_back(str.substr(first, i - first));
                //cout << vec.back() << endl;
                first = i + 1;
            }
        }
        vec.push_back(str.substr(first));
        //cout << vec.back() << endl;
    }
    int cur;
    vector<string> vec;
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
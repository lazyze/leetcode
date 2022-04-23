/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if (root == nullptr) return {};
        vector<vector<int>> ans;
        queue<pair<Node*, int>> que;
        que.push(make_pair(root, 1));
        int height;
        int cur = 0;
        vector<int> vec;
        Node* tmp;
        while (!que.empty()) {
            tmp = que.front().first;
            height = que.front().second;
            que.pop();
            if(height > cur) {
                if(vec.size() > 0) {
                    ans.push_back(vec);   
                }
                vec.clear();
                cur++; 
            }
            vec.push_back(tmp->val);
            for (auto it : tmp->children) {
                que.push(make_pair(it, height + 1));
            }
        }
        ans.push_back(vec);
        return ans;
    }
    //确定层数

};
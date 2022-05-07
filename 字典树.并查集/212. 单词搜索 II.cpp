/* dfs + 哈希 解法
class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        r = board.size();
        c = board[0].size();
        visit = vector<vector<bool>> (r, vector<bool>(c, false));
        for (auto& it : words) {
            uset.insert(it);
        }
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                string str = "";
                dfs(board, i, j, str);
            }
        }
        vector<string> rt(ans.begin(), ans.end());
        return rt;
    }

    void dfs(vector<vector<char>>& board, int i, int j, string& str) {
        str += board[i][j];
        if(uset.find(str) != uset.end()){
            ans.insert(str);
        } 
        if(str.size() >= 10) return;
        visit[i][j] = true;
        for (int k = 0; k < 4; k++) {
            int a = i + dx[k];
            int b = j + dy[k];
            if (a < 0 || b < 0 || a >= r || b >= c) continue;
            string tmp = str;
            if(!visit[a][b]) dfs(board, a, b, tmp);
        }
        visit[i][j] = false;
        
    }

    int r;
    int c;
    vector<vector<bool>> visit;
    unordered_set<string> ans;
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    unordered_set<string> uset;
};
*/


// dfs + 字典树（trie）
class Solution {
    struct Node{
        string* word;
        unordered_map<char, Node*> child;
        Node () {
            word = nullptr;
        }
    };

    void insert(string& str) {
        Node* root = head;
        for (auto& it : str) {
            if(root->child.find(it) == root->child.end()) {
                Node* ch = new Node;
                root->child[it] = ch;
            }
            root = root->child[it];
        }
        root->word = &str;
    }
    
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        r = board.size();
        c = board[0].size();
        visit = vector<vector<bool>> (r, vector<bool>(c, false));
        head = new Node;
        for (auto& it : words) {
            insert(it);
        }
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                dfs(board, i, j, head);
            }
        }
        //vector<string> rt(ans.begin(), ans.end());
        return ans;
    }

    void dfs(vector<vector<char>>& board, int i, int j, Node* cur) {
        //未发现
        if(cur->child.find(board[i][j]) == cur->child.end()) return ;
        Node* fa = cur;
        cur = cur->child[board[i][j]];
        if(cur->word != nullptr) {
            ans.push_back(*cur->word);
            cur->word = nullptr;
        }
        //删除已经加入答案的字符串
        if(cur->child.empty()) {
            fa->child.erase(board[i][j]);
        }
        visit[i][j] = true;
        for (int k = 0; k < 4; k++) {
            int a = i + dx[k];
            int b = j + dy[k];
            if (a < 0 || b < 0 || a >= r || b >= c) continue;
            if(!visit[a][b]) dfs(board, a, b, cur);
        }
        visit[i][j] = false;
    }

    int r;
    int c;
    vector<vector<bool>> visit;
    vector<string> ans;
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    Node* head;
};
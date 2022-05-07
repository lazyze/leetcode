class Trie {
    struct Node{
        int count;
        unordered_map<char, Node*> child;
        Node() {
            count = 0;
        }
    };
public:
    Trie() {
        head = new Node;
    }
    
    void insert(string word) {
        //处理每个字母
        Node* cur = head;
        for (auto& it : word) {
            //没有则插入
            if(cur->child.find(it) == cur->child.end()) {
                Node* ch = new Node();
                cur->child[it] = ch;
                cur = ch;
            } else {
                cur = cur->child[it];
            }
        }
        cur->count++;
    }
    
    bool search(string word) {
        //处理每个字母
        Node* cur = head;
        for (auto& it : word) {
            //没有则插入
            if(cur->child.find(it) == cur->child.end()) {
                return false;
            } else {
                cur = cur->child[it];
            }
        }
        return cur->count > 0;
    }
    
    bool startsWith(string prefix) {
         //处理每个字母
        Node* cur = head;
        for (auto& it : prefix) {
            //没有则插入
            if(cur->child.find(it) == cur->child.end()) {
                return false;
            } else {
                cur = cur->child[it];
            }
        }
        return cur->count >= 0;
    }
    Node* head;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
class LRUCache {
public:

    struct Node{
        int key;
        int val;
        Node* pre;
        Node* next;
    };

    LRUCache(int capacity) {
        this->capacity = capacity;
        pro = new Node;
        end = new Node;
        pro->next = end;
        end->pre = pro;
    }
    
    int get(int key) {
        if (rd.find(key) == rd.end()) return -1;
        deleteNode(rd[key]);
        insertNode(rd[key]);
        return rd[key]->val;
    }
    
    void put(int key, int value) {
        if (rd.find(key) == rd.end()) {
            Node* node = new Node;
            node->key = key;
            node->val = value;
            if(rd.size() == capacity) {
                rd.erase(end->pre->key);
                deleteNode(end->pre);
            }
            rd[key] = node;
            insertNode(node);
        } else {
            deleteNode(rd[key]);
            insertNode(rd[key]);
            rd[key]->val = value;
        }
    }

    void deleteNode(Node* node) {
        //操作前后两次
        node->pre->next = node->next;
        node->next->pre = node->pre;
    }

    void insertNode(Node* node) {
        //处理插入位置后一个节点
        node->next = pro->next;
        pro->next->pre = node;
        //处理插入位置前一个节点
        pro->next = node;
        node->pre = pro;
    }

private:
    int capacity;
    unordered_map<int, Node*> rd;
    Node* pro;
    Node* end;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
class LRUCache {
public:
    struct ListNode{
        int key;
        int value;
        ListNode* pre;
        ListNode* next;
    };

    LRUCache(int capacity) {
        //***注意不能直接为capacity = capacity;
        this->capacity = capacity;
        pro = new ListNode;
        end = new ListNode;
        pro->next = end;
        pro->pre = nullptr;
        end->pre = pro;
        end->next = nullptr;
        size = 0;
    }
    
    int get(int key) {
        if (record.find(key) != record.end()) {
            //原位置删除节点
            record[key]->pre->next = record[key]->next;
            record[key]->next->pre = record[key]->pre;
            //更新查询节点位置
            //处理插入位置后节点
            record[key]->next = pro->next;
            pro->next->pre = record[key];
            //处理插入位置前节点
            pro->next = record[key];
            record[key]->pre = pro;
            return record[key]->value;
        } else return -1;
    }
    
    void put(int key, int value) {
        if(get(key) == -1) {
            ListNode* build = new ListNode;
            build->key = key;
            build->value = value;
            if (size < capacity){
                size++; 
            } else {
                //删除最后一个节点 end->pre
                int tmp = end->pre->key;
                //cout << size << "," << capacity << endl;
                //cout << key << "," << end->pre->value << endl;
                end->pre->pre->next = end;
                end->pre = end->pre->pre;
                record.erase(tmp);
            }
            //新建节点插入链表中
            //处理插入位置后节点
            build->next = pro->next;
            pro->next->pre = build;
            //处理插入位置前节点
            pro->next = build;
            build->pre = pro;
            record[key] = build;
        } else record[key]->value = value;
    }

    int capacity;
    int size;
    ListNode* pro;
    ListNode* end;
    unordered_map<int, ListNode*> record;


};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
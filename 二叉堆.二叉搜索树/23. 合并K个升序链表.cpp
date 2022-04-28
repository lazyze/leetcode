// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */


// //二叉堆解法
// struct Node{
//     int key;
//     ListNode* node;
//     Node(int key, ListNode* ptr) : key(key), node(ptr) {}
// };

// bool operator <(const Node& a, const Node& b) {
//     return a.key > b.key;
// }

// class Solution {
// public:
//     ListNode* mergeKLists(vector<ListNode*>& lists) {
//         priority_queue<Node> pqueue;
//         for (auto it : lists) {
//             if(it != nullptr)
//                 pqueue.push(Node(it->val, it));
//         }
//         ListNode* protect = new ListNode;
//         ListNode* tail = protect;
//         while (!pqueue.empty()) {
//             Node tmp = pqueue.top();
//             pqueue.pop();
//             tail->next = tmp.node;
//             tail = tail->next;
//             ListNode* in = tmp.node->next;
//             if(in != nullptr) pqueue.push(Node(in->val, in));
//         }
//         return protect->next;
//     }
// };


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

 struct Node{
        int key;
        ListNode* node;
        Node(int key, ListNode* ptr) : key(key), node(ptr) {}
    };


//自己实现二叉堆
class BininaryHeap {
public:
    bool empty() {
        return heap.empty();
    }
    void push(Node a) {
        heap.push_back(a);
        heapifyUp(heap.size() - 1);
    }

    Node pop() {
        Node rt = heap[0];
        heap[0] = heap[heap.size() - 1];
        heap.pop_back();
        heapifyDown(0);
        return rt;
    }
private:
//从位置0开始存储 l = pos * 2 + 1， r = pos * 2 + 2
//父节点 p = (pos - 1) / 2
    void heapifyUp(int pos) {
         while (pos != 0) {
            int p = (pos - 1) / 2;
            if (heap[pos].key >= heap[p].key) return;
            swap(heap[pos], heap[p]);
            pos = p;
        }
    }
    void heapifyDown(int pos) {
        int child = pos * 2 + 1;
        while (child < heap.size()) {
            int otherchild = child + 1;
            if(otherchild < heap.size() && heap[child].key > heap[otherchild].key)
                child = otherchild;
            if(heap[pos].key > heap[child].key) {
                swap(heap[pos], heap[child]);
                pos = child;
                child = pos * 2 + 1;
            }
            else return;
        }
    }
    vector<Node> heap;
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        BininaryHeap pqueue;
        for (auto it : lists) {
            if(it != nullptr)
                pqueue.push(Node(it->val, it));
        }
        ListNode* protect = new ListNode;
        ListNode* tail = protect;
        while (!pqueue.empty()) {
            Node tmp = pqueue.pop();
            tail->next = tmp.node;
            tail = tail->next;
            ListNode* in = tmp.node->next;
            if(in != nullptr) pqueue.push(Node(in->val, in));
        }
        return protect->next;
    }
};
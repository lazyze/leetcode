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
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* pro = new ListNode;
        pro->next = nullptr;
        ListNode* temp = head;
        ListNode* kend = nullptr;
        ListNode* next = nullptr;
        ListNode* pre = pro;
        while (temp) {
            kend = getK(temp, k);
            
            if (kend == nullptr) {
                pre->next = temp;
                break;
            } 
            //cout << kend->val << " " << temp->val << endl;
            next = kend->next;
            reverse(temp, kend);
            pre->next = kend;
            pre = temp;
            temp->next = next;
            temp = next;
        }
        return pro->next;
    }

    ListNode* getK(ListNode* head, int k) {
       for (int i = 0; i < k - 1; i++) {
           if (head){
               head = head->next;
           } else return nullptr;
       }
       return head;
    }

    void reverse(ListNode* begin, ListNode* end) {
        ListNode* pre = nullptr;
        ListNode* temp = nullptr;
        while (begin != end) {
            temp = begin->next;
            begin->next = pre;
            pre = begin;
            begin = temp;
        }
        begin->next = pre;
    }
};
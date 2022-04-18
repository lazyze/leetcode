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
    ListNode* reverseList(ListNode* head) {
        ListNode *pro = new ListNode;
        pro->next = nullptr;
        ListNode *pre = nullptr;
        ListNode *rem;
        while (head) {
            rem = head->next;
            head->next = pre;
            pre = head;
            head = rem;
        }
        pro->next = pre;
        return pro->next;
    }
};
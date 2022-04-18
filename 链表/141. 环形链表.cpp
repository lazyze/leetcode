/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == NULL || head->next == NULL) return false;
        ListNode *slow = head;
        ListNode *quick = head->next;
        while (head) {
            if(slow->next != NULL) slow = slow->next;
            else return false;
            if (quick->next != NULL && quick->next->next != NULL) quick = quick->next->next;
            else return false;
            if (slow == quick) return true;

        }
        return false;
    }
};
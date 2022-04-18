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
    ListNode *detectCycle(ListNode *head) {
        //if (head == NULL || head->next == NULL) return NULL;
        ListNode *slow = head;
        ListNode *quick = head;
        ListNode *pro = head;
        while (quick) {
            if(slow->next != NULL) slow = slow->next;
            else return NULL;
            if (quick->next != NULL && quick->next->next != NULL) quick = quick->next->next;
            else return NULL;
            if (slow == quick) {
                ListNode *temp = pro;
                while (temp != slow) {
                    temp = temp->next;
                    slow = slow->next;
                }
                return temp;
            }
        }
        return NULL;
    }
};
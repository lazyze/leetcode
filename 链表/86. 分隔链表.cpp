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

//思路
//找到第一个大于等于x的节点记为rem
//新建保护节点pro，且为插入节点inpos
//遍历链表，新建标记变量flag，判断遍历的节点在rem前后位置
//若遍历节点小于rem：
//  1）若遍历节点node在rem之前，将遍历节点插入inpos后，更新inpos，继续遍历链表
//  2）若遍历节点node在rem之后，将遍历节点node前后节点连接上（及删除node节点），将遍历节点的后继节点设为rem，插入inpos后，更新inpos，继续遍历节点
//若遍历节点大于rem，继续遍历链表

//注意事项：*1遍历节点在rem之后时，删除node节点时，pre节点无需变化
//举例 2->3->7->5->6->8 比较值为7，则删除节点5时，结果为2->3->5->7->6->8 pre节点依旧是7
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* pro = new ListNode;
        pro->next = head;
        ListNode* inpos = pro;
        //ListNode* temp = nullptr;
        ListNode* rem = nullptr;
        ListNode* pre = nullptr;
        ListNode* temp = nullptr;
        bool flag = false;
        //找到第一个大于等于x的节点记为rem
        while (head) {
            if (head->val >= x) {
                rem = head;
                break;
            }
            head = head->next;
        }
        head = pro->next;
        //遍历链表
        while (head) {
            temp = head->next;
            //小于rem节点值
            if (head->val < x) {
                if (flag) {
                    //遍历节点在rem之后，删除节点
                    pre->next = head->next;
                    head->next = rem;
                }
                inpos->next = head;
                inpos = head;
            } else pre = head; //大于rem节点值
            //标记遍历节点在rem位置
            if (head == rem) flag = true;
            head = temp;
        }
        return pro->next;
    }
};
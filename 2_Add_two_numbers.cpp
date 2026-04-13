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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int total, nxt = 0;
        ListNode* res = new ListNode();
        ListNode* cur = res;
        while (l1 != nullptr && l2 != nullptr){
            total = l1->val+l2->val+nxt;
            cur->next = new ListNode(total%10);
            nxt = total/10; l1 = l1->next;
            l2 = l2->next;
            cur = cur->next;
            }
        while (l1 != nullptr){
            cur->next = new ListNode((l1->val+nxt)%10);
            nxt = (l1->val+nxt)/10;
            cur = cur->next;
            l1 = l1->next;
            }
        while (l2 != nullptr){
            cur->next = new ListNode((l2->val+nxt)%10);
            nxt = (l2->val+nxt)/10;
            cur = cur->next;
            l2 = l2->next;
            }
        if (nxt != 0){
            cur->next = new ListNode(nxt);
            }
        return res->next;
    }
};

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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) return head;
        if (head->next == nullptr) return head;
        ListNode *res = new ListNode(0, head);
        ListNode *cur = res;
        cur = cur->next;
        while (cur->next != nullptr){
            if (cur->val == cur->next->val){
                cur->next = cur->next->next;
            }
            else cur = cur->next;
        }
        return res->next;
    }
};

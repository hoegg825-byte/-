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
    ListNode* swapPairs(ListNode* head) {
        ListNode* tmp = new ListNode(0);
        tmp->next = head;
        ListNode* cur = tmp;
        while (cur -> next != nullptr && cur->next->next != nullptr){
            ListNode* l1 = cur->next;
            ListNode* l2 = cur->next->next;
            ListNode* l3 = cur->next->next->next;
            cur->next = l2;
            l2->next = l1;
            l1->next = l3;
            cur = l1;
        }
        return tmp->next;
    }
};

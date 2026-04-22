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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr) return head;
        int n = 0;
        ListNode *tmp = new ListNode(0);
        tmp->next = head;
        tmp = tmp->next;
        while (true){
            n++;
            if (tmp->next == nullptr) break;
            else tmp = tmp->next;
        }
        tmp->next = head;
        tmp = head;
        for (int i=0; i<(n-1) - (k%n); i++){
            tmp = tmp->next; 
        }
        ListNode *res = tmp->next;
        tmp->next = nullptr;
        return res;
    }
};

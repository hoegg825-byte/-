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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* res = new ListNode(-1, head);
        ListNode* pre_left = res;
        for (int i=1; i<left; i++) pre_left = pre_left->next;
        ListNode* right_ = pre_left;
        for (int i=0; i<right-left+1; i++) right_ = right_->next;
        ListNode* left_ = pre_left->next;
        ListNode* af_right = right_->next;
        pre_left->next = nullptr;
        right_->next = nullptr;
        Reverse(left_);
        pre_left->next = right_;
        left_->next = af_right;
        return res->next;
    }

    void Reverse(ListNode* start){
        ListNode* pre = nullptr;
        ListNode* d = start;
        while (d != nullptr){
            ListNode* nxt = d->next;
            d->next = pre;
            pre = d;
            d = nxt;
        }
    }
};

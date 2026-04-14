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
    struct cmp{
        bool operator() (ListNode* a, ListNode* b){
            return a->val > b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* ans = new ListNode(0);
        ListNode* cur = ans;
        priority_queue<ListNode*, vector<ListNode*>, cmp> q;
        for (int i=0; i<lists.size(); i++){
            if (lists[i] != nullptr) q.push(lists[i]);
        }
        while (!q.empty()){
            ListNode* t = q.top();
            q.pop();
            cur->next = new ListNode(t->val);
            cur = cur->next;
            if (t->next != nullptr) q.push(t->next);
        }
        return ans->next;
    }
};

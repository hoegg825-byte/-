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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        return build(head, nullptr);
    }
    ListNode* getmid(ListNode*left, ListNode*right){
        ListNode* slow = left;
        ListNode* fast = left;
        while (fast != right && fast->next != right){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    TreeNode* build(ListNode* left, ListNode* right){
        if (left == right) return nullptr;
        ListNode* mid = getmid(left, right);
        TreeNode* root = new TreeNode(mid->val);
        root->left = build(left, mid);
        root->right = build(mid->next, right);
        return root;
    }
};

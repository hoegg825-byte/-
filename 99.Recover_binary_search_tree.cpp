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
    void recoverTree(TreeNode* root) {
        vector<int> vt;
        inorder(root, vt);
        int error_1 = -1, error_2 = -1;
        for (int i=1; i<vt.size(); i++){
            if (vt[i] < vt[i-1]){
                error_2 = i;
                if (error_1 == -1) error_1 = i-1;
                else break;
            }
        }
        int finish = 2;
        fix(root, vt[error_1], vt[error_2], finish);
    }
    void inorder(TreeNode* node, vector<int> &vt){
        if (node == nullptr) return;
        inorder(node->left, vt);
        vt.push_back(node->val);
        inorder(node->right, vt);
    }
    void fix(TreeNode* cur, int e1, int e2, int &finish){
        if (cur == nullptr) return;
        if (cur->val == e1){
            cur->val = e2;
            if (--finish == 0) return;
        }
        else if (cur->val == e2){
            cur->val = e1;
            if (--finish == 0) return;
        }
        fix(cur->left, e1, e2, finish);
        fix(cur->right, e1, e2, finish);
    }
};

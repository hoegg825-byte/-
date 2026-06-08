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
    bool isSymmetric(TreeNode* root) {
        queue<pair<TreeNode*, TreeNode*>> q;
        q.push({root->left, root->right});
        while (!q.empty()){
            TreeNode* a = q.front().first;
            TreeNode* b = q.front().second;
            q.pop();
            if (a == nullptr && b == nullptr) continue;
            if (a == nullptr || b == nullptr) return false;
            if (a->val != b->val) return false;
            q.push({a->left, b->right});
            q.push({a->right, b->left});
        }
        return true;
    }
};

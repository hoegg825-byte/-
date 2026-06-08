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
    bool isValidBST(TreeNode* root) {
        return dfs(root, -2147483648, 2147483647);
    }
    bool dfs(TreeNode* cur, long long mn, long long mx){
        if (cur == nullptr) return true;
        long long v = cur->val;
        if (v < mn || v > mx) return false;
        return dfs(cur->left, mn, v-1) && dfs(cur->right, v+1, mx);
    }
};

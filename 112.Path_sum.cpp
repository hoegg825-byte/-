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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return false;
        return dfs(root, targetSum, 0);
    }
    bool dfs(TreeNode* node, int &targetSum, int cnt){
        cnt += node->val;
        if (node->left == nullptr && node->right == nullptr) return (cnt == targetSum);
        bool findleft = false, findright = false;
        if (node->left != nullptr) findleft = dfs(node->left, targetSum, cnt);
        if (node->right != nullptr) findright = dfs(node->right, targetSum, cnt);
        return findleft || findright;
    }
};

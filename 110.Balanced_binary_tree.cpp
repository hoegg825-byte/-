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
    bool isBalanced(TreeNode* root) {
        bool balanced = true;
        dfs(root, balanced);
        return balanced;
    }
    int dfs(TreeNode* node, bool &balanced){
        if (node == nullptr) return 0;
        int left_deep = dfs(node->left, balanced);
        int right_deep = dfs(node->right, balanced);
        if (abs(left_deep - right_deep) > 1) balanced = false;
        return max(left_deep, right_deep) + 1;
    }
};

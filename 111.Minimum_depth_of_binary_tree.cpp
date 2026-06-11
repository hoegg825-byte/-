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
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        int leftdeep = minDepth(root->left);
        int rightdeep = minDepth(root->right);
        if (leftdeep == 0 || rightdeep == 0) return max(leftdeep, rightdeep)+1;
        else return min(leftdeep, rightdeep)+1;
    }
};

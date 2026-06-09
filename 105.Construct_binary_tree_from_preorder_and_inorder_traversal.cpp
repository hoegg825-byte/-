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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        return build(preorder, inorder, 0, n-1, 0, n-1);
    }
    TreeNode* build(vector<int> &preorder, vector<int> &inorder, int pl, int pr, int il, int ir){
        if (pl > pr) return nullptr;
        int t = preorder[pl];
        TreeNode* root = new TreeNode(t);
        int mid = find(inorder.begin()+il, inorder.begin()+ir, t) - inorder.begin();
        int lsize = mid-il;
        root->left = build(preorder, inorder, pl+1, pl+lsize, il, mid-1);
        root->right = build(preorder, inorder, pl+lsize+1, pr, mid+1, ir);
        return root;
    }
};

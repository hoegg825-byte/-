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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int p = inorder.size()-1;
        return build(postorder, inorder, p, 0, inorder.size()-1);
    }
    TreeNode* build(vector<int> &postorder, vector<int> &inorder, int &p, int il, int ir){
        if (il > ir) return nullptr;
        int v = postorder[p];
        int mid = find(inorder.begin(), inorder.end(), v) - inorder.begin();
        TreeNode* root = new TreeNode(v);
        p--;
        root->right = build(postorder, inorder, p, mid+1, ir);
        root->left = build(postorder, inorder, p, il, mid-1);
        return root;
    }
};

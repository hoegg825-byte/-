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
    vector<TreeNode*> generateTrees(int n) {
        return MakeTree(1, n);
    }
    vector<TreeNode*> MakeTree(int start, int end){
        if (start > end) return {nullptr};
        vector<TreeNode*> res;
        for (int i=start; i<=end; i++){
            vector<TreeNode*> LeftTree = MakeTree(start, i-1);
            vector<TreeNode*> RightTree = MakeTree(i+1, end);
            for (auto &Left : LeftTree){
                for (auto &Right : RightTree){
                    TreeNode* tmp = new TreeNode(i);
                    tmp->left = Left;
                    tmp->right = Right;
                    res.push_back(tmp);
                }
            }
        }
        return res;
    }
};

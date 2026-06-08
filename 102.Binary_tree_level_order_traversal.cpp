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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) return {};
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        vector<vector<int>> vt;
        while (!q.empty()){
            int cur = q.front().second;
            vector<int> tmp = {};
            while (!q.empty() && q.front().second == cur){
                TreeNode* v = q.front().first;
                q.pop();
                tmp.push_back(v->val);
                if (v->left != nullptr) q.push({v->left, cur+1});
                if (v->right != nullptr) q.push({v->right, cur+1});
            }
            vt.push_back(tmp);
        }
        return vt;
    }
};

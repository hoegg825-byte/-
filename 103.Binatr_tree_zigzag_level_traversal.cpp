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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == nullptr) return {};
        bool left_to_right = true;
        vector<vector<int>> res;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()){
            deque<int> dq;
            int n = q.size();
            for (int i=0; i<n; i++){
                TreeNode* v = q.front();
                q.pop();
                if (left_to_right) dq.push_back(v->val);
                else dq.push_front(v->val);
                if (v->left != nullptr) q.push(v->left);
                if (v->right != nullptr) q.push(v->right);
            }
            // vector<int> vt(dq.size());
            // for (int i=0; i<dq.size(); i++){
            //     vt[i] = dq.front();
            //     dq.pop_front();
            // }
            //res.push_back(vt);
            res.emplace_back(vector<int>{dq.begin(), dq.end()});
            left_to_right = !left_to_right;
        }
        return res;
    }
};

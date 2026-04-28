class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> tmp;
        backtracking(1, n, k, tmp, ans);
        return ans;
    }
    void backtracking(int idx, int &n, int &k, vector<int> &tmp, vector<vector<int>> &ans){
        if (tmp.size() == k){
            ans.push_back(tmp);
            return;
        }
        for (int i=idx; i<=n; i++){
            tmp.push_back(i);
            backtracking(i+1, n, k, tmp, ans);
            tmp.pop_back();
        }
    }
};

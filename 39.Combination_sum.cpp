class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target){
        vector<vector<int>> ans;
        vector<int> tmp;
        backtracking(candidates, target, tmp, ans, 0, 0);
        return ans;
    }
    void backtracking(vector<int> &candidates,int &target, vector<int> &tmp, vector<vector<int>> &ans, int sum, int idx){
        if (sum >= target){
            if (sum == target) ans.push_back(tmp);
            return;
        }
        for (int i = idx; i<candidates.size(); i++){
            int x = candidates[i];
            tmp.push_back(x);
            backtracking(candidates, target, tmp, ans, sum+x, i);
            tmp.pop_back();
        }
    }
};

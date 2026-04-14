class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> tmp;
        backtracking(0, 0, ans, tmp, candidates, target);
        return ans;
    }
    void backtracking(int idx, int sum_, vector<vector<int>> &ans ,vector<int> &tmp, vector<int> &candidates, int &target){
        if (sum_ > target) return;
        if (sum_ == target){
            ans.push_back(tmp);
            return;
        }
        for (int i=idx; i<candidates.size(); i++){
            if (i>idx && candidates[i] == candidates[i-1]) continue;
            if (candidates[i] > target) break;
            tmp.push_back(candidates[i]);
            backtracking(i+1, sum_+candidates[i], ans, tmp, candidates, target);
            tmp.pop_back();
        }
    }
};

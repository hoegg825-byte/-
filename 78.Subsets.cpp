class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> tmp;
        for (int i=0; i<=nums.size(); i++){
            tmp = {};
            backtracking(0, i, nums, tmp, ans);
        }
        return ans;
    }
    void backtracking(int idx, int &n, vector<int> &nums, vector<int> &tmp, vector<vector<int>> &ans){
        if (tmp.size() == n){
            ans.push_back(tmp);
            return;
        }
        for (int i=idx; i<nums.size(); i++){
            tmp.push_back(nums[i]);
            backtracking(i+1, n, nums, tmp, ans);
            tmp.pop_back();
        }
    }
};

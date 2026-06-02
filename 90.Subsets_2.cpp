class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> tmp;
        sort(nums.begin(), nums.end());
        backtracking(nums, ans, tmp, 0);
        return ans;
    }
    void backtracking(const vector<int> &nums, vector<vector<int>> &ans, vector<int> &tmp, int idx){
        ans.push_back(tmp);
        for (int i = idx; i<nums.size(); i++){
            if (i > idx && nums[i] == nums[i-1]) continue;
            tmp.push_back(nums[i]);
            backtracking(nums, ans, tmp, i+1);
            tmp.pop_back();
        }
    }
};

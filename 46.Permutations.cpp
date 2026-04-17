class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> tmp;
        unordered_map<int, bool> mp;
        backtracking(tmp, ans, nums, mp);
        return ans;
    }
    void backtracking(vector<int> &tmp, vector<vector<int>> &ans, vector<int> &nums, unordered_map<int, bool> &mp){
        if (tmp.size() == nums.size()){
            ans.push_back(tmp);
            return;
        }
        for (int i=0; i<nums.size(); i++){
            if (mp[i]) continue;
            mp[i] = true;
            tmp.push_back(nums[i]);
            backtracking(tmp, ans, nums, mp);
            tmp.pop_back();
            mp[i] = false;
        }
    }
};

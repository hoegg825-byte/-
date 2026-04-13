class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans = {};
        for (int i=0; i<nums.size()-2; i++){
            if (i>0 && nums[i] == nums[i-1]) continue;
            if (nums[i+1]+nums[i+2] > -nums[i]) break;
            if (nums[nums.size()-1]+nums[nums.size()-2] < -nums[i]) continue;
            int l=i+1, r = nums.size()-1;
            while (l<r){
                int sum_ = nums[l]+nums[r];
                if (sum_ == -nums[i]){
                    ans.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    while (l<r && nums[l] == nums[l-1]) l++;
                    r--;
                    while (l<r && nums[r] == nums[r+1]) r--;
                }
                else if (sum_ > -nums[i]) r--;
                else l++; 
            }
        }
        return ans;
    }
};

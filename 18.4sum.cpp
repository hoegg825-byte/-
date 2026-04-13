class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i=0; i<=n-4; i++){
            if (i>0 && nums[i] == nums[i-1]) continue;
            if ((long long)nums[i]+nums[i+1]+nums[i+2]+nums[i+3] > target) break;
            if ((long long)nums[i]+nums[n-1]+nums[n-2]+nums[n-3] < target) continue;
            for (int j=i+1; j<=n-3; j++){
                if (j>i+1 && nums[j] == nums[j-1]) continue;
                if ((long long)nums[i]+nums[j]+nums[j+1]+nums[j+2]>target) break;
                if ((long long)nums[i]+nums[j]+nums[n-1]+nums[n-2]<target) continue;
                int l = j+1, r = n-1;
                while (l<r){
                    long long t = (long long)target - nums[i] - nums[j];
                    if (nums[l]+nums[r] == t){
                        ans.push_back({nums[i], nums[j], nums[l], nums[r]});
                        int curl = nums[l];
                        while (r>l && nums[l] == curl) l++;
                        int curr = nums[r];
                        while (r>l && nums[r] == curr) r--;
                    }
                    else if (nums[l]+nums[r]>t) r--;
                    else l++;
                }
            }
        }
        return ans;
    }
};

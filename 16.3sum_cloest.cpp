class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = 1e9;
        for (int i=0; i<n; i++){
            int l = i+1, r = n-1;
            while (l<r){
                int L = nums[l], R = nums[r];
                int cur = nums[i] + L + R;
                if (cur == target) return cur;
                if (abs(ans-target)>abs(cur-target)) ans = cur;
                if (cur > target){
                    r--;
                }
                else {
                    l++;
                }
            }
        }
        return ans;
    }
};

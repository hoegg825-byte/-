class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int start = low_bound(nums, target);
        if (start == nums.size() || nums[start] != target) return {-1, -1};
        int end = low_bound(nums, target+1)-1;
        return {start, end};
    }
    int low_bound(vector<int> &nums, int target){
        int l = 0, r = nums.size()-1;
        while (l<=r){
            int mid = (l+r)/2;
            if (nums[mid] >= target) r = mid-1;
            else l = mid+1;
        }
        return l;
    }
};

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for (int i=0; i<nums.size(); i++){
            if (nums[i] == INT_MIN) continue;
            while (nums[i]-1 != i){
                if (nums[i]-1 >= nums.size() || nums[i]-1 < 0) break;
                if (nums[i] == nums[nums[i]-1]) break;
                swap(nums[i], nums[nums[i]-1]);
            }
        }
        for (int i=0; i<nums.size(); i++){
            if (nums[i] != i+1) return i+1;
        }
        return nums.size()+1;
    }
};

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int cur_end=0, max_end=0;
        if (nums.size() == 1) return true;
        bool j = false;
        for (int i=0; i<nums.size(); i++){
            if (max_end < i+nums[i]){
                max_end = i+nums[i];
                if (max_end >= nums.size()-1) return true;
                j = true;
            }
            if (i == cur_end){
                if (j){
                cur_end = max_end;
                j = false;
                }
                else return false;
            }
        }
        return true;
    }
};

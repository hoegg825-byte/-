class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=1;
        int pre = nums[0];
        for (int j=1; j<nums.size(); j++){
            if (pre != nums[j]){
                nums[i] = nums[j];
                pre = nums[j];
                i++;
            }
        }
        return i;
    }
};

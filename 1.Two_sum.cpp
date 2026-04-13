class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        for (int i=0; i<nums.size(); i++){
            int u = nums[i];
            int t = target-u;
            if (mp.count(t)) return {i, mp[t]};
            else mp[u] = i;
        }
        return {};
    }
};

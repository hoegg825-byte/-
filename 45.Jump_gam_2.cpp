class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0;      // 跳躍次數
        int current_end = 0; // 目前這一步能到的最遠邊界
        int farthest = 0;    // 下一步最遠能衝到的位置
        
        // 為什麼是 nums.size() - 1 ? 思考一下
        for (int i = 0; i < nums.size() - 1; i++) {
            farthest = max(farthest, i+nums[i]);
            if (i == current_end) {
                jumps++;
                current_end = farthest;
            }
        }
        return jumps;
    }
};

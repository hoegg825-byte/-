class Solution {
public:
    int climbStairs(int n) {
        int last_2 = 1, last_1 = 1;
        for (int i=2; i<=n; i++){
            int tmp = last_2+last_1;
            last_2 = last_1;
            last_1 = tmp;
        }
        return last_1;
    }
};

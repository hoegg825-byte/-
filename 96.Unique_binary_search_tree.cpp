class Solution {
public:
    int numTrees(int n) {
        // G(n) = sum(G(i-1) * G(n-i) for i in 1~n
        vector<int> dp(n+1, -1);
        dp[0] = 1;
        dp[1] = 1;
        return G(n, dp);
    }
    int G(int n, vector<int> &dp){
        if (dp[n] != -1) return dp[n];
        int sum_ = 0;
        for (int i=1; i<=n; i++){
            sum_ += G(i-1, dp) * G(n-i, dp);
        }
        return dp[n] = sum_;
    }
};

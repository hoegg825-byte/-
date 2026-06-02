class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp(s.size()+1, -1);
        return dfs(dp, s, s.size()-1);
    }
    int dfs(vector<int> &dp, string &s, int idx){
        if (idx < 0) return 1;
        if (dp[idx] != -1) return dp[idx];
        int ans = 0;
        if (s[idx] != '0') ans += dfs(dp, s, idx-1);
        if (idx > 0){
            int subs = stoi(s.substr(idx-1, 2));
            if (subs >= 10 && subs <= 26) ans += dfs(dp, s, idx-2);
        }
        return dp[idx] = ans;
    }
};

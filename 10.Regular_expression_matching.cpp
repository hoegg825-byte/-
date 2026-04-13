class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.size()+1, vector<int> (p.size()+1, -1));
        return solve(0, 0, s, p, dp);
    }
    bool solve(int i, int j, string &s, string &p, vector<vector<int>> &dp){
        if (dp[i][j] != -1) return dp[i][j];
        if (j == p.size()) return i == s.size();
        bool first_match = (i<s.size() && (s[i] == p[j] || p[j] == '.'));
        bool ans;
        if (j+1<p.size() && p[j+1] == '*'){
            bool skip_str = solve(i, j+2, s, p, dp);
            bool use_str = false;
            if (first_match) use_str = solve(i+1, j, s, p, dp);
            ans = skip_str || use_str;
        }
        else{
            ans = first_match && solve(i+1, j+1, s, p, dp);
        }
        return dp[i][j] = ans;
    }
};

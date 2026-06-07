class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() == 0) return s2 == s3;
        if (s2.size() == 0) return s1 == s3;
        if (s1.size() + s2.size() != s3.size()) return false;
        vector<vector<int>> dp(s1.size()+1, vector<int>(s2.size()+1, -1));
        return IsInterleave(dp, 0, 0, s1, s2, s3);
    }
    bool IsInterleave(vector<vector<int>> &dp, int i, int j, string &s1, string &s2, string &s3){
        if (i == s1.size() && j == s2.size()) return true;
        if (dp[i][j] != -1) return (bool)dp[i][j];
        bool Pair = false;
        if (i < s1.size() && s1[i] == s3[i+j]) Pair |= IsInterleave(dp, i+1, j, s1, s2, s3);
        if (j < s2.size() && s2[j] == s3[i+j]) Pair |= IsInterleave(dp, i, j+1, s1, s2, s3);
        if (Pair) return dp[i][j] = 1;
        else return dp[i][j] = 0;
    }
};

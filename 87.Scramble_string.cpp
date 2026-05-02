class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1.size() != s2.size()) return false;
        int n = s1.size();
        vector<vector<vector<int>>> memo(n, vector<vector<int>> (n, vector<int> (n+1, -1)));
        return dfs(0, 0, n, s1, s2, memo);
    }
    bool dfs(int i, int j, int len, const string &s1, const string &s2, vector<vector<vector<int>>> &memo){
        //if (memo[i][j][len] != -1) return memo[i][j][len];
            if (len == 1) return memo[i][j][len] = s1[i] == s2[j];
        for (int l = 1; l<len; l++){
            if (dfs(i, j, l, s1, s2, memo) && dfs(i+l, j+l, len-l, s1, s2, memo)) return memo[i][j][len] = true;
            if (dfs(i, j+len-l, l, s1, s2, memo) && dfs(i+l, j, len-l, s1, s2, memo)) return memo[i][j][len] = true;
        }
        return memo[i][j][len] = false;
    }
};

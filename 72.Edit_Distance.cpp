// 方法1.記憶化遞迴
class Solution {
public:
    int minDistance(string word1, string word2) {
        int i = word1.size(), j = word2.size();
        if (i == 0) return j;
        if (j == 0) return i;
        vector<vector<int>> dp(i, vector<int>(j, -1));
        return edit(i-1, j-1, word1, word2, dp);
    }
    int edit(int i, int j, const string &word1, const string &word2, vector<vector<int>> &dp){
        if (i == -1 || j == -1){
            return max(i, j)+1;
        }
        if (dp[i][j] != -1) return dp[i][j];
        if (word1[i] == word2[j]){
            return dp[i][j] = edit(i-1, j-1, word1, word2, dp);
        }
        int Insert = edit(i, j-1, word1, word2, dp);
        int Delete = edit(i-1, j, word1, word2, dp);
        int Change = edit(i-1, j-1, word1, word2, dp);
        return dp[i][j] = min(min(Insert, Delete), Change) + 1;
    }
};
//方法2.動態規劃dp
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<vector<int>> dis(n+1, vector<int>(m+1, 0));
        for (int i=0; i<=n; i++) dis[i][0] = i;
        for (int i=0; i<=m; i++) dis[0][i] = i;
        for (int i=1; i<=n; i++){
            for (int j=1; j<=m; j++){
                if (word1[i-1] == word2[j-1]){
                    dis[i][j] = dis[i-1][j-1];
                }
                else
                {
                    int Insert = dis[i-1][j];
                    int Delete = dis[i][j-1];
                    int Change = dis[i-1][j-1];
                    dis[i][j] = min(Insert, min(Delete, Change)) + 1;
                }
            }
        }
        return dis[n][m];
    }
};

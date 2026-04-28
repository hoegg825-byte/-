class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();
        vector<vector<bool>> use;
        vector<vector<int>> dis = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        bool final_find  = false;
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                use.assign(n, vector<bool> (m, false));
                use[i][j] = true;
                if (board[i][j] == word[0]) dfs(i, j, 1, final_find, n, m, board, use, word, dis);
                if (final_find) return true;
            }
        }
        return false;
    }
    void dfs(int r, int c, int idx, bool &final_find, const int &n, const int &m, const vector<vector<char>> &board, vector<vector<bool>> &use, const string &word, const vector<vector<int>> &dis){
        if (idx == word.size()){
            final_find = true;
            return;
        }
        int cur_need = word[idx];
        for (int i=0; i<4; i++){
            int cr = r+dis[i][0], cc = c+dis[i][1];
            if (cr >=0 && cr < n && cc >= 0 && cc < m && !use[cr][cc] && board[cr][cc] == cur_need){
                use[cr][cc] = true;
                dfs(cr, cc, idx+1, final_find, n, m, board, use, word, dis);
                if (final_find) return;
                use[cr][cc] = false;
            }
        }
    }
};

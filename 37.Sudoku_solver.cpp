class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> rows(9, vector<bool> (10, false));
        vector<vector<bool>> cols(9, vector<bool> (10, false));
        vector<vector<bool>> area(9, vector<bool> (10, false));
        for (int i=0; i<9; i++){
            for (int j=0; j<9; j++){
                char c = board[i][j];
                if (c != '.'){
                    rows[i][c-'0'] = true;
                    cols[j][c-'0'] = true;
                    area[getarea(i, j)][c-'0'] = true;
                }
            }
        }
        bool finish = false;
        backtracking(board, rows, cols, area, 0, finish);
    }
    int getarea(int r, int c){
        return 3*(r/3)+(c/3);
    }
    void backtracking(vector<vector<char>> &board, vector<vector<bool>> &rows, vector<vector<bool>> &cols, vector<vector<bool>> &area, int idx, bool &finish){
        if (idx == 81){
            finish = true;
            return;
        }
        int r = idx/9, c = idx%9;
        char cur = board[r][c];
        if (cur != '.') backtracking(board, rows, cols, area, idx+1, finish);
        else {
            for (int i=1; i<=9; i++){
                int areanum = getarea(r, c);
                bool currow = rows[r][i];
                bool curcol = cols[c][i];
                bool curarea = area[areanum][i];
                if (!currow && !curcol && !curarea){
                    rows[r][i] = true;
                    cols[c][i] = true;
                    area[areanum][i] = true;
                    board[r][c] = i+'0';
                    backtracking(board, rows, cols, area, idx+1, finish);
                    if (finish) return;
                    rows[r][i] = currow;
                    cols[c][i] = curcol;
                    area[areanum][i] = curarea;
                    board[r][c] = '.';
                }
            }
        }
    }
};

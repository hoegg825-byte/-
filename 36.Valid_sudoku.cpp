class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<char, int> mp;
        for (int i=0; i<9; i++){
            mp.clear();
            for (int j=0; j<9; j++){
                if (board[i][j] == '.') continue;
                if (mp.count(board[i][j])) return false;
                else mp[board[i][j]]++;
            }
            mp.clear();
            for (int j=0; j<9; j++){
                if (board[j][i] == '.') continue;
                if (mp.count(board[j][i])) return false;
                else mp[board[j][i]]++;
            }
        }
        for (int i=0; i<9; i+=3){
            for (int j=0; j<9; j+=3){
                mp.clear();
                for (int c=i; c<i+3; c++){
                    for (int r=j; r<j+3; r++){
                        if (board[r][c] == '.') continue;
                        if (mp.count(board[r][c])) return false;
                        else mp[board[r][c]]++;
                    }
                }
            }
        }
        return true;
    }
};

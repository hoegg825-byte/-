class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<bool> col(n, false);
        map<int, bool> left;
        map<int, bool> right;
        string s = "";
        for (int i=0; i<n; i++) s+='.';
        vector<string> tmp(n, s);
        vector<vector<string>> ans;
        backtracking(n, 0, col, left, right, tmp, ans);
        return ans;
    }
    void backtracking(int &n, int r, vector<bool> &col, map<int, bool> &left, map<int, bool> &right, vector<string> &tmp, vector<vector<string>> &ans){
        if (r == n){
            ans.push_back(tmp);
            return;
        }
        for (int i=0; i<n; i++){
            int lid = r-i, rid = i+r;
            if (!col[i] && !left[lid] && !right[rid]){
                col[i] = true;
                left[lid] = true;
                right[rid] = true;
                tmp[r][i] = 'Q';
                backtracking(n, r+1, col, left, right, tmp, ans);
                col[i] = false;
                left[lid] = false;
                right[rid] = false;
                tmp[r][i] = '.';
            }
        }
    }
};

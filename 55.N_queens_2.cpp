class Solution {
public:
    int totalNQueens(int n) {
        vector<bool> col(n, false);
        map<int, bool> left;
        map<int, bool> right;
        string s = "";
        for (int i=0; i<n; i++) s+='.';
        vector<string> tmp(n, s);
        int ans = 0;
        backtracking(n, 0, col, left, right, tmp, ans);
        return ans;
    }
    void backtracking(int &n, int r, vector<bool> &col, map<int, bool> &left, map<int, bool> &right, vector<string> &tmp, int &ans){
        if (r == n){
            ans++;
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

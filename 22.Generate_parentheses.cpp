class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s;
        backtracking(0, 0, s, n, ans);
        return ans;
    }
    void backtracking(int o, int c, string s, int &n, vector<string> &ans){
        if (o==c && o == n){
            ans.push_back(s);
            return;
        }
        if (o < n){
            backtracking(o+1, c, s+'(', n, ans);
        }
        if (c < o){
            backtracking(o, c+1, s+')', n, ans);
        }
    }
};

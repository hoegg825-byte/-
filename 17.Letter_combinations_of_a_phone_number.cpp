class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<vector<char>> c = {{'a', 'b', 'c'}, {'d', 'e', 'f'}, {'g', 'h', 'i'}, {'j', 'k', 'l'}, {'m', 'n', 'o'}, {'p', 'q', 'r', 's'}, {'t', 'u', 'v'}, {'w', 'x', 'y', 'z'}};
        vector<string> ans;
        string s = "";
        backtracking(c, ans, s, digits, 0);
        return ans;
    }

    void backtracking(vector<vector<char>> &c, vector<string> &vt, string &s, string &digits, int idx){
        if (s.size() == digits.size()){
            vt.push_back(s);
            return;
        }
        for (char cur : c[digits[idx]-'2']){
            s += cur;
            backtracking(c, vt, s, digits, idx+1);
            s = s.substr(0, s.size()-1);
        }
    }
};

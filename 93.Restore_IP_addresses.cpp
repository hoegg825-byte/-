class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        string tmp;
        backtracking(s, res, tmp, 0, 0);
        return res;
    }
    void backtracking(string &s, vector<string> &res, string &tmp, int idx, int cnt){
        if (cnt == 4 || idx == s.size()){
            if (cnt == 4 && idx == s.size()) res.push_back(tmp);
            return;
        }
        string backup = tmp;
        if (idx != 0) tmp += ".";
        tmp += s[idx];
        backtracking(s, res, tmp, idx+1, cnt+1);
            if (s[idx] != '0'){
            if (idx+1 < s.size()){
                tmp += s[idx+1];
                backtracking(s, res, tmp, idx+2, cnt+1);
            }
            if (idx+2 < s.size()){
                tmp += s[idx+2];
                if (stoi(s.substr(idx, 3)) <= 255) backtracking(s, res, tmp, idx+3, cnt+1);
            }
        }
        tmp = backup;
    }
};

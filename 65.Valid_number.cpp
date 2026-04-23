class Solution {
public:
    bool isNumber(string s) {
        int idx = -1;
        int n = s.size();
        for (int i=0; i<n; i++){
            if (s[i] == 'e' || s[i] == 'E'){
                if (idx == -1) idx = i;
                else return false;
            }
        }
        if (idx == -1) return check(s, 0, n-1, false);
        else return check(s, 0, idx-1, false) && check(s, idx+1, n-1, true);
    }

    bool check(const string &s, int start, int end, bool mustdigit){
        bool digit = false, point = false;
        if (s[start] == '+' || s[start] == '-') start++;
        for (int i=start; i<=end; i++){
            if (s[i] == '.'){
                if (point || mustdigit) return false;
                point = true;
            }
            else if (isdigit(s[i])){
                digit = true;
            }
            else return false;
        }
        return digit;
    }
};

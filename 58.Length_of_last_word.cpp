class Solution {
public:
    int lengthOfLastWord(const string &s) {
        int n = s.size()-1;
        for (int i=s.size()-1; i>=0; i--){
            if (s[i] == ' ') n--;
            else break;
        }
        for (int i=n; i>=0; i--){
            if (s[i] == ' ') return n-i;
        }
        return n+1;
    }
};

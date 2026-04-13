class Solution {
public:
    string longestPalindrome(string s) {
        string ans = "";
        for (int i=0; i<s.size(); i++){
            int l=i, r = i+1;
            while (l >= 0 && r < s.size() && s[l] == s[r]){
                l--;
                r++;
            }
            string tmp = s.substr(l+1, r-l-1);
            if (ans.size()<tmp.size()) ans = tmp;
        }
        for (int i=0; i<s.size(); i++){
            int l=i-1, r = i+1;
            while (l >= 0 && r < s.size() && s[l] == s[r]){
                l--;
                r++;
            }
            string tmp = s.substr(l+1, r-l-1);
            if (ans.size()<tmp.size()) ans = tmp;
        }
        return ans;
    }
};

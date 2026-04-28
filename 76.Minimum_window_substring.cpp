class Solution {
public:
    string minWindow(string s, string t) {
        map<char, int> need;
        map<char, int> win;
        for (char c:t) need[c]++;
        int l = 0, r = 0;
        int start = 0, mn = 1e9;
        int valid = 0;
        while (r < s.size()){
            char c = s[r];
            r++;
            if (need.count(c)){
                win[c]++;
                if (win[c] == need[c]){
                    valid++;
                }
            }
            while (valid == need.size()){
                if (r - l < mn){
                    start = l;
                    mn = r-l;
                }
                char d = s[l];
                l++;
                if (need.count(d)){
                    if (win[d] == need[d]) valid--;
                    win[d]--;
                }
            }
        }
        string ans;
        if (mn == 1e9) return ans;
        else return s.substr(start, mn);
    }
};

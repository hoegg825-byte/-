class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> mp;
        int l = 0, res = 0;
        for (int r=0; r< (int)s.size(); r++){
            if (mp.count(s[r])){
                l = max(l, mp[s[r]]+1);
            }
            mp[s[r]] = r;
            res = max(res, r-l+1);
        }
        return res;
    }
};

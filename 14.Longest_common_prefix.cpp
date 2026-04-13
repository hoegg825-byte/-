class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string s1 = *max_element(strs.begin(), strs.end());
        string s2 = *min_element(strs.begin(), strs.end());
        for (int i=0; i<s1.size(); i++){
            if (i>=s2.size() || s1[i] != s2[i]) return s1.substr(0, i+1);
        }
        return s1;
    }
};

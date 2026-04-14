class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.size() > haystack.size()) return -1;
        for (int i=0; i<=haystack.size()-needle.size(); i++){
            if (haystack[i] == needle[0]){
                bool same = true;
                for (int j=1; j<needle.size(); j++){
                    if (haystack[i+j] != needle[j]) {same = false; break;}
                }
                if (same) return i;
            }
        }
        return -1;
    }
};

class Solution {
public:
    string countAndSay(int n) {
        return rle(n);
    }
    string rle(int idx){
        if (idx == 1) return "1";
        string s = rle(idx-1);
        string ans = "";
        char cur = s[0];
        int cnt = 1;
        for (int i=1; i<s.size(); i++){
            if (s[i] != cur){
                ans += cnt+'0';
                ans += cur;
                cnt = 1;
                cur = s[i];
            }
            else cnt++;
        }
        ans += cnt+'0';
        ans += cur;
        return ans;
    }
};

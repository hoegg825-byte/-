class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> vt(numRows, "");
        int idx = 0;
        while (true){
            for (int i=0; i<numRows && idx<s.size(); i++){
                vt[i] += s[idx];
                idx++;
            }
            if (idx>=s.size()) break;
            for (int i=numRows-2; i>0 && idx<s.size(); i--){
                vt[i] += s[idx];
                idx++;
            }
            if (idx>=s.size()) break;
        }
        string ans = "";
        for (string x:vt) ans += x;
        return ans;
    }
};

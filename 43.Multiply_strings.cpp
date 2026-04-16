class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        int len1 = num1.size(), len2 = num2.size();
        vector<int> ans(len1+len2, -1);
        for (int i=0; i<len1; i++){
            for (int j=0; j<len2; j++){
                int res = (num1[i]-'0')*(num2[j]-'0');
                if (ans[i+j] != -1) ans[i+j] += res;
                else ans[i+j] = res;
            }
        }
        while (ans[ans.size()-1]==-1) ans.pop_back();
        int nxt = 0;
        string s;
        for (int i=ans.size()-1; i>=0; i--){
            ans[i] += nxt;
            nxt = ans[i] / 10;
            s += (char)(ans[i]%10)+'0';
        }
        if (nxt != 0) s += (char)nxt+'0';
        reverse(s.begin(), s.end());
        return s;
    }
};

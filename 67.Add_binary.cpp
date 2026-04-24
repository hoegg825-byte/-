class Solution {
public:
    string addBinary(string a, string b) {
        int nxt = 0;
        int lena = a.size(), lenb = b.size();
        vector<int> res;
        for (int i=0; i<min(lena, lenb); i++){
            char ca = a[lena-1-i], cb = b[lenb-1-i];
            int r = (ca-'0')+(cb-'0')+nxt;
            res.push_back(r%2);
            nxt = r/2;
        }
        if (lena > lenb){
            for (int i = lenb; i<lena; i++){
                int r = (a[lena-1-i] - '0')+nxt;
                res.push_back(r%2);
                nxt = r/2;
            }
        }
        else if (lenb > lena){
            for (int i = lena; i<lenb; i++){
                int r = (b[lenb-1-i] - '0')+nxt;
                res.push_back(r%2);
                nxt = r/2;
            }
        }
        if (nxt>0)res.push_back(nxt);
        string s;
        for (int i=res.size()-1; i>=0; i--) s+= (char)res[i]+'0';
        return s;
    }
};

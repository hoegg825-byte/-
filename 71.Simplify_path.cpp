class Solution {
public:
    string simplifyPath(string path) {
        vector<string> st;
        path += "/";
        string cur;
        for (int i=1; i<path.size(); i++){
            char c = path[i];
            if (c == '/'){
                if (cur == "."){
                    cur = "";
                } else if (cur == ".."){
                    cur = "";
                    if (st.empty()) continue;
                    st.pop_back();
                } else {
                    if (cur.size() == 0) continue;
                    st.push_back(cur);
                    cur = "";
                }
            }
            else cur += c;
        }
        if (cur.size()>0) st.push_back(cur);
        string ans;
        for (string &s:st){
            ans += '/'+s;
        }
        if (st.empty()) return "/";
        return ans;
    }
};

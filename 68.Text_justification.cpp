class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        vector<string> tmp;
        int cur_width = 0;
        for (int i=0; i<words.size(); i++){
            if (words[i].size() + cur_width + tmp.size() <= maxWidth){
                tmp.push_back(words[i]);
                cur_width += words[i].size();
            }
            else {
                ans.push_back(fill_space(tmp, maxWidth, false));
                tmp = vector<string> {words[i]};
                cur_width = words[i].size();
            }
        }
        ans.push_back(fill_space(tmp, maxWidth, true));
        return ans;
    }
    string fill_space(vector<string> &words, int &maxWidth, bool last){
        int cur_len = 0;
        for (int i=0; i<words.size(); i++){
            if (i != words.size()-1) words[i] += ' ';
            cur_len += words[i].size();
        }
        if (last || words.size() == 1){
            words[words.size()-1] += string(maxWidth-cur_len, ' ');
        }
        else {
            for (int i=0; ++cur_len <= maxWidth; i = (i+1)%(words.size()-1)) words[i] += ' ';
        }
        string ans;
        for (string x: words) ans += x;
        return ans;
    }
};

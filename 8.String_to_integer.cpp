class Solution {
public:
    int myAtoi(string s) {
        long long n=0;
        bool is_ = false;
        int idx=0;
        while (idx < s.size() && s[idx] == ' '){
            idx++;
        }
        if (s[idx] == '-') {is_ = true; idx++;}
        else if (s[idx] == '+') idx++;
        for (int i = idx; i<s.size(); i++){
            char c = s[i];
            if (isdigit(c)){
                n = n*10+(c-'0');
                if (n > INT_MAX || n < INT_MIN) break;
            }
            else {
                break;
            }
        }
        if (is_) n *= -1;
        if (n > INT_MAX) return INT_MAX;
        else if (n < INT_MIN) return INT_MIN;
        else return n;
    }
};

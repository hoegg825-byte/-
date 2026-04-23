class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int nxt = 0;
        digits[digits.size()-1] += 1;
        for (int i=digits.size()-1; i>=0; i--){
            digits[i] += nxt;
            nxt = digits[i]/10;
            digits[i] = digits[i]%10;
        }
        if (nxt>0){
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};

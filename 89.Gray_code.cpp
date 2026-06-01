class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res = {0};
        while (n--){
            for (int i = res.size()-1; i>=0; i--){
                res[i] <<= 1;
                res.push_back(res[i]+1);
            }
        }
        return res;
    }
};

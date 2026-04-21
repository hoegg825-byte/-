class Solution {
public:
    string getPermutation(int n, int k) {
        int fact[10] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
        string ans = "";
        vector<bool> used(n+1, false);
        for (int i=1; i<=n; i++){
            int cnt = fact[n-i];
            for (int j=1; j<=n; j++){
                if (used[j]) continue;
                if (k > cnt) k -= cnt;
                else {
                    ans += (char)j+'0';
                    used[j] = true;
                    break;
                }
            }
        }
        return ans;
    }
};

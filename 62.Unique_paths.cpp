class Solution {
public:
    int uniquePaths(int m, int n) {
        return combinations(m+n-2, m-1);
    }
    int combinations(int n, int k) {
    if (k < 0 || k > n) return 0;
    if (k == 0 || k == n) return 1;
    if (k > n / 2) k = n - k;

    long long res = 1;
    for (int i = 1; i <= k; ++i) {
        res = res * (n - i + 1) / i;
    }
    return res;
    }
};

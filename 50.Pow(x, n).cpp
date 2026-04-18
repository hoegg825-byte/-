class Solution {
public:
    map<int, double> mp;
    double myPow(double x, int n) {
        if (mp.count(n)) return mp[n];
        if (n < 5 && n >= 0){
            double cur = 1;
            for (int i=0; i<n; i++) cur *= x;
            return mp[n] = cur;
        }
        if (n < 0 && n > -5){
            double cur = 1;
            for (int i=0; i<-n; i++){
                cur /= x;
            }
            return mp[n] = cur;
        }
        return mp[n] = myPow(x, n/2)*myPow(x, n/2+n%2);
    }

};

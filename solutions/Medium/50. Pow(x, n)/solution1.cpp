class Solution {
public:
    double expSquaring(double x, long N) {
        double ans = 1.0;
        while (N > 0) {
            if (N & 1) ans *= x;
            N >>= 1;
            x *= x;
        }
        return ans;
    }

    double myPow(double x, int n) {
        long N = n;
        return n >= 0 ? expSquaring(x, N) : expSquaring(1 / x, -N);
    }
};
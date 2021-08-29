class Solution {
public:
    double expSquaring(double x, long N) {
        if (N == 0) return 1;
        if (N & 1) return x * expSquaring(x * x, N / 2);
        else return expSquaring(x * x, N / 2);
    }

    double myPow(double x, int n) {
        long N = n;
        return n >= 0 ? expSquaring(x, N) : expSquaring(1 / x, -N);
    }
};
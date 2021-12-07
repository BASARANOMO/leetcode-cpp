class Solution {
    const int MOD = 1337;
public:
    int pow(int x, int n) {
        int res = 1;
        while (n) {
            if (n % 2) res = (long) res * x % MOD;
            x = (long) x * x % MOD;
            n /= 2;
        }
        return res;
    }
    int superPow(int a, vector<int>& b) {
        int ans = 1;
        for (int elem : b) ans = (long) pow(ans, 10) * pow(a, elem) % MOD;
        return ans;
    }

};
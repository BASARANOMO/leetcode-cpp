class Solution {
public:
    bool isPerfectSquare(int num) {
        double x0 = num, x1;
        while (true) {
            x1 = (x0 + num / x0) / 2;
            if (x0 - x1 < 1e-6) break;
            x0 = x1;
        }
        int x = (int) x0;
        return x * x == num;
    }
};
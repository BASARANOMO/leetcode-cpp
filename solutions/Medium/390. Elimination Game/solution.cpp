class Solution {
public:
    int lastRemaining(int n) {
        int a1 = 1;
        int step = 1, cnt = n, k = 0;
        while (cnt > 1) {
            if (k % 2 == 0) a1 = a1 + step;
            else {
                a1 = (cnt % 2 == 0) ? a1 : a1 + step;
            }
            k++;
            step *= 2;
            cnt /= 2;
        }
        return a1;
    }
};
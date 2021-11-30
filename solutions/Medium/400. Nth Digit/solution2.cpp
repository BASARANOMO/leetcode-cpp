class Solution {
public:
    int findNthDigit(int n) {
        int d = 1, cnt = 9;
        while (n > (long) d * cnt) {
            n -= d * cnt;
            d++;
            cnt *= 10;
        }
        int idx = n - 1;
        int start = (int) pow(10, d - 1);
        int num = start + idx / d;
        int digitIdx = idx % d;
        int digit = (num / (int) (pow(10, d - digitIdx - 1))) % 10;
        return digit;
    }
};
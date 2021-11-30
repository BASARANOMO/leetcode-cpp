class Solution {
public:
    int findNthDigit(int n) {
        int low = 1, high = 9;
        while (low < high) {
            int mid = (high - low) / 2 + low;
            if (totalDigits(mid) < n) low = mid + 1;
            else high = mid;
        }
        int d = low; // 第n位数所对应数字有d位
        int prevDigits = totalDigits(d - 1);
        int index = n - prevDigits - 1; // 第n位数在全部d位数中的index
        int start = (int) pow(10, d - 1); // d位数的第一个数为10e(d-1)
        int num = start + index / d; // 第n位数所在数字
        int digitIndex = index % d; // 第n位数在num的第digitIndex位
        int digit = (num / (int) (pow(10, d - digitIndex - 1))) % 10; // 先去掉数字num在digitIndex位之后（右侧）的余数，再取最末位数
        return digit;
    }
    int totalDigits(int length) {
        int digits = 0;
        int curLength = 1, curCount = 9;
        while (curLength <= length) {
            digits += curLength * curCount;
            curLength++;
            curCount *= 10;
        }
        return digits;
    }
};
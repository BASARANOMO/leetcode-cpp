class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num == 1) return true;
        int left = 1, right = min(num / 2, 46340), mid;
        while (left <= right) {
            mid = (left + right) / 2;
            if (mid * mid == num) return true;
            else if (mid * mid < num) left = mid + 1;
            else right = mid - 1;
        }
        return false;
    }
};
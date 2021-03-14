class Solution {
public:
    int climbStairs(int n) {
        int val1 = 1, val2 = 1, temp;
        for (int i = 1; i < n; i++) {
            temp = val1 + val2;
            val1 = val2;
            val2 = temp;
        }
        return val2;
    }
};

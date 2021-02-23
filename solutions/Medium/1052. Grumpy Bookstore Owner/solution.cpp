class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        // sliding window
        int res = 0;
        int n = customers.size();
        for (int i = 0; i < n; i++) {
            if (grumpy[i] == 0) res += customers[i];
        }
        int inc = 0;
        for (int i = 0; i < X; i++) {
            inc += grumpy[i] * customers[i];
        }

        int max = inc;
        for (int i = 0; i < n - X; i++) {
            inc = inc - grumpy[i] * customers[i] + grumpy[i + X] * customers[i + X];
            max = inc > max ? inc : max;
        }
        return res + max;
    }
};

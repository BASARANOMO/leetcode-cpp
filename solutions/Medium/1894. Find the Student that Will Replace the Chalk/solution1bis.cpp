class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        if (chalk[0] > k) return 0;
        int n = chalk.size();
        for (int i = 1; i < n; i++) {
            chalk[i] += chalk[i - 1];
            if (chalk[i] > k) return i;
        }
        k %= chalk[n - 1];
        // binary search
        int left = 0, right = n - 1, mid;
        while (left < right) {
            mid = (left + right) >> 1;
            if (chalk[mid] > k) right = mid;
            else left = mid + 1;
        }
        return right;
    }
};
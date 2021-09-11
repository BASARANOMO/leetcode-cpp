class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n = chalk.size();
        vector<long long> preSum(n + 1);
        for (int i = 0; i < n; i++) preSum[i + 1] = preSum[i] + chalk[i];
        k %= preSum[n];
        // binary search
        int left = 0, right = n, mid;
        while (left <= right) {
            mid = (left + right) >> 1;
            if (preSum[mid] > k) right = mid - 1;
            else left = mid + 1;
        }
        return right;
    }
};
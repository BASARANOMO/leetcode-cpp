class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        double left = 0.0, right = 1.0;
        while (true) {
            double mid = (left + right) / 2; // guessed cutoff val
            int i = -1, cnt = 0;
            int x = 0, y = 1; // x / y is the max frac visited
            for (int j = 1; j < n; j++) {
                while ((double)arr[i + 1] / arr[j] < mid) {
                    i++;
                    if (arr[i] * y > arr[j] * x) {
                        x = arr[i];
                        y = arr[j];
                    }
                }
                cnt += i + 1;
            }
            if (cnt == k) {
                return {x, y};
            }
            else if (cnt < k) left = mid;
            else right = mid;
        }
    }
};
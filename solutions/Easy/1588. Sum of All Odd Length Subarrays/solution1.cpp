#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n = arr.size();
        int ans = accumulate(arr.begin(), arr.end(), 0);
        int presum = arr[0], anchor = 0, sum;
        for (int i = 3; i < n + 1; i += 2) {
            presum += arr[anchor + 1] + arr[anchor + 2];
            anchor += 2;
            sum = presum;
            ans += sum;
            for (int idx = 1; idx < n - i + 1; idx++) {
                sum += arr[idx + i - 1] - arr[idx - 1];
                ans += sum;
            }
        }
        return ans;
    }
};
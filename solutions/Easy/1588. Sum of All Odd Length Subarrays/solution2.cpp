#include <vector>
using namespace std;

class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n = arr.size();
        int res = 0;
        int left, left_even, left_odd, right, right_even, right_odd;
        for (int i = 0; i < n; i++) {
            left = i + 1, right = n - i;
            left_even = (left + 1) / 2;
            left_odd = left / 2;
            right_even = (right + 1) / 2;
            right_odd = right / 2;
            res += (left_even * right_even + left_odd * right_odd) * arr[i];
        }
        return res;
    }
};
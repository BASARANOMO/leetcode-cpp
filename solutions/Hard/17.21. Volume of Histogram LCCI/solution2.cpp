#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int lSum = 0, rSum = 0, sum = 0;
        int leftMax = 0, rightMax = 0;
        for (int i = 0; i < n; i++) {
            leftMax = max(leftMax, height[i]);
            lSum += leftMax;
            sum += height[i];
        }
        for (int i = n - 1; i >= 0; i--) {
            rightMax = max(rightMax, height[i]);
            rSum += rightMax;
        }
        return lSum + rSum - leftMax * n - sum;
    }
};
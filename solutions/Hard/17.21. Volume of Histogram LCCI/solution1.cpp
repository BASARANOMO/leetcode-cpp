#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int leftMax = 0, rightMax = 0;
        int left = 0, right = n - 1;
        int res = 0;
        while (left < right) {
            leftMax = max(height[left], leftMax);
            rightMax = max(height[right], rightMax);
            if (height[left] < height[right]) {
                res += leftMax - height[left];
                left++;
            } else {
                res += rightMax - height[right];
                right--;
            }
        }
        return res;
    }
};
class Solution {
public:
    int trap(vector<int>& height) {
        // two pointers
        int left = 0, right = height.size() - 1;
        int leftMax = 0, rightMax = 0;
        int ans = 0;
        while (left < right) {
            leftMax = leftMax > height[left] ? leftMax : height[left];
            rightMax = rightMax > height[right] ? rightMax : height[right];
            if (height[left] < height[right]) {
                ans += leftMax - height[left];
                left++;
            } else {
                ans += rightMax - height[right];
                right--;
            }
        }
        return ans;
    }
};
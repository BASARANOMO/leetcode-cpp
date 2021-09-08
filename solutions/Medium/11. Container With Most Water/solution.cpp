class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0, curr = 0;
        int n = height.size();
        int left = 0, right = n - 1;
        while (left < right) {
            curr = min(height[left], height[right]) * (right - left);
            ans = curr > ans ? curr : ans;
            if (height[left] < height[right]) left++;
            else right--;
        }
        return ans;
    }
};
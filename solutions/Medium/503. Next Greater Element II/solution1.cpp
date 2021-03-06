class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, -1);
        int curr, next;
        for (int i = 0; i < n; i++) {
            curr = nums[i];
            for (int j = 0; j < n; j++) {
                if (nums[(i + j) % n] > curr) {
                    res[i] = nums[(i + j) % n];
                    break;
                }
            }
        }
        return res;
    }
};

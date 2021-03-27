class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, -1);
        stack<int> monotoneS;
        for (int i = 0; i < 2 * n; i++) {
            while (!monotoneS.empty() && nums[monotoneS.top()] < nums[i % n]) {
                res[monotoneS.top()] = nums[i % n];
                monotoneS.pop();
            }
            monotoneS.push(i % n);
        }
        return res;
    }
};

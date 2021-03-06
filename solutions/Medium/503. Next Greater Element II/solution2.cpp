class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, -1);
        stack<int> monotoneS;
        int temp = 0;
        for (int i = 0; i < 2 * n; i++) {
            while (!monotoneS.empty() && nums[monotoneS.top()] < nums[i % n]) {
                temp = monotoneS.top();
                monotoneS.pop();
                res[temp] = nums[i % n];
            }
            monotoneS.push(i % n);
        }
        return res;
    }
};

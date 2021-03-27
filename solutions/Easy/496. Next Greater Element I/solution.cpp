class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        vector<int> res(n1, -1);
        stack<int> monotoneStack;
        unordered_map<int, int> numsMap;
        for (int i = 0; i < n1; i++) numsMap[nums1[i]] = i;
        for (int i = 0; i < n2; i++) {
            while (!monotoneStack.empty() && nums2[monotoneStack.top()] < nums2[i]) {
                if (numsMap.find(nums2[monotoneStack.top()]) != numsMap.end()) {
                    res[numsMap[nums2[monotoneStack.top()]]] = nums2[i];
                }
                monotoneStack.pop();
            }
            monotoneStack.push(i);
        }
        return res;
    }
};

class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> numCnt;
        for (int num : nums) numCnt[num]++;
        int res = 0;
        for (auto [key, val] : numCnt) {
            if (numCnt.find(key + 1) != numCnt.end()) res = max(res, val + numCnt[key + 1]);
        }
        return res;
    }
};
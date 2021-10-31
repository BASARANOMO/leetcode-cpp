class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xorsum = 0;
        for (int num : nums) xorsum ^= num;
        int lowest = (xorsum == INT_MIN ? xorsum : xorsum & -xorsum);
        int type1 = 0, type2 = 0;
        for (int num : nums) {
            if (lowest & num) type1 ^= num;
            else type2 ^= num;
        }
        vector<int> ans {type1, type2};
        return ans;
    }
};
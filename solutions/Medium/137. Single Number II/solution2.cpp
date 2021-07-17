class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        int sum_i = 0;
        for (int i = 0; i < 32; i++) {
            sum_i = 0;
            for (int num : nums) sum_i += (num >> i) & 1;
            if (sum_i % 3 != 0) res |= (1 << i);
        }
        return res;
    }
};

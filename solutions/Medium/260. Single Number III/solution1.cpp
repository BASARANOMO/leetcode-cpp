#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int i = 0; i < nums.size(); i++) freq[nums[i]]++;
        vector<int> ans;
        for (const auto& [num, occ] : freq) {
            if (occ == 1) ans.push_back(num);
        }
        return ans;
    }
};
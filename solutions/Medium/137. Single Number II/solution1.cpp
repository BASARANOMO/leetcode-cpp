#include <unordered_map>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // hash
        unordered_map<int, int> h_map;
        for (int num : nums) {
            h_map[num]++;
            if (h_map[num] == 3) h_map.erase(num);
        }
        return h_map.begin()->first;
    }
};

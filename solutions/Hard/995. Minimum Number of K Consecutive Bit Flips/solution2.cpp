#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        queue<int> q;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (!q.empty() && q.front() == i) q.pop();
            if ((nums[i] + q.size()) % 2 == 0) {
                if (i + k > nums.size()) return -1;
                ans++;
                q.push(i + k);
            }
        }
        return ans;
    }
};
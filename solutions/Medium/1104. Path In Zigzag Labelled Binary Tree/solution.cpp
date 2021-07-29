#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        int depth = ceil(log2(label + 1));
        int cnt_in_row = (depth % 2 == 0) ? pow(2, depth) - label : label - pow(2, depth - 1) + 1;
        vector<int> ans;
        for (int i = depth; i > 0; i--) {
            if (i % 2 == 0) ans.push_back(pow(2, i) - cnt_in_row);
            else ans.push_back(pow(2, i - 1) + cnt_in_row - 1);
            cnt_in_row = (cnt_in_row + 1) >> 1;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

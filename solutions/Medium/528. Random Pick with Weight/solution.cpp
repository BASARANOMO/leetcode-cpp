#include <random>
#include <vector>
using namespace std;

class Solution {
public:
    mt19937 gen;
    uniform_int_distribution<int> dis;
    vector<int> preSum;
    Solution(vector<int>& w) {
        preSum.push_back(w[0]);
        for (int i = 1; i < w.size(); i++) preSum.push_back(preSum.back() + w[i]);
        dis = uniform_int_distribution<>(1, accumulate(w.begin(), w.end(), 0));
        gen = mt19937(random_device{}());
    }
    
    int pickIndex() {
        int x = dis(gen);
        return lower_bound(preSum.begin(), preSum.end(), x) - preSum.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
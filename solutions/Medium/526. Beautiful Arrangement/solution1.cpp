#include <vector>
using namespace std;

class Solution {
public:
    int ans;
    void dfs(int n, vector<int>& curr, vector<int>& idx) {
        if (curr.size() == n) {
            ans++;
            return;
        }
        int curr_pos = curr.size() + 1;
        for (int i = 1; i < n + 1; i++) {
            if (idx[i] == 0 && (i % curr_pos == 0 || curr_pos % i == 0)) {
                idx[i] = 1;
                curr.push_back(i);
                dfs(n, curr, idx);
                idx[i] = 0;
                curr.pop_back();
            }
        }

    }
    int countArrangement(int n) {
        ans = 0;
        vector<int> curr;
        vector<int> idx(n + 1);
        dfs(n, curr, idx);
        return ans;
    }
};
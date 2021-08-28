#include <vector>
using namespace std;

class Solution {
public:
    int ans;
    vector<vector<int>> matches;
    void dfs(int n, int idx, vector<int>& vis) {
        if (idx == n) {
            ans++;
            return;
        }
        for (int i = 0; i < matches[idx + 1].size(); i++) {
            if (vis[matches[idx + 1][i]] == 0) {
                vis[matches[idx + 1][i]] = 1;
                dfs(n, idx + 1, vis);
                vis[matches[idx + 1][i]] = 0;
            }
        }
    }
    int countArrangement(int n) {
        ans = 0;
        matches.resize(n + 1);
        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j < n + 1; j++) {
                if (i % j == 0 || j % i == 0) matches[i].push_back(j);
            }
        }
        vector<int> vis(n + 1);
        dfs(n, 0, vis);
        return ans;
    }
};
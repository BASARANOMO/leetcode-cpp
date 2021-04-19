class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int res = 0;
        int l1, l2;
        vector<vector<pair<int, int>>> helper(m + 1, vector<pair<int, int>>(n + 1));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) helper[i][j] = make_pair(helper[i][j - 1].first + grid[i - 1][j - 1],
                helper[i - 1][j].second + grid[i - 1][j - 1]);
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    for (int l = res + 1; l < min(m - i + 1, n - j + 1); l++) {
                        l1 = helper[i + 1][j + l].first - helper[i + 1][j].first;
                        l2 = helper[i + l][j + 1].second - helper[i][j + 1].second;
                        if (l1 != l || l2 != l) break;
                        l1 = helper[i + l][j + l].first - helper[i + l][j].first;
                        l2 = helper[i + l][j + l].second - helper[i][j + l].second;
                        if (l1 == l && l2 == l) {
                            res = max(res, l);
                        }
                    }
                }
            }
        }
        return res * res;
    }
};

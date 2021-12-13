class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> rowMax(n);
        vector<int> colMax(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                rowMax[i] = rowMax[i] > grid[i][j] ? rowMax[i] : grid[i][j];
                colMax[j] = colMax[j] > grid[i][j] ? colMax[j] : grid[i][j];
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                ans += (min(rowMax[i], colMax[j]) - grid[i][j]);
            }
        }
        return ans;
    }
};
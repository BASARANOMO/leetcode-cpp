#include <vector>
using namespace std;

class Solution {
    int m, n;
public:
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    res++;
                    dfs(grid, i, j);
                }
            }
        }
        return res;
    }

    void dfs(vector<vector<char>>& grid, int x, int y) {
        grid[x][y] = '0';
        if (x >= 1 && grid[x - 1][y] == '1') dfs(grid, x - 1, y);
        if (x < m - 1 && grid[x + 1][y] == '1') dfs(grid, x + 1, y);
        if (y >= 1 && grid[x][y - 1] == '1') dfs(grid, x, y - 1);
        if (y < n - 1 && grid[x][y + 1] == '1') dfs(grid, x, y + 1);
    }
};

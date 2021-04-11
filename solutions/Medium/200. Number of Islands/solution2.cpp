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
                    bfs(grid, i, j);
                }
            }
        }
        return res;
    }

    void bfs(vector<vector<char>>& grid, int x, int y) {
        queue<pair<int, int>> q;
        q.push(make_pair(x, y));
        while (!q.empty()) {
            auto temp = q.front();
            q.pop();
            x = temp.first;
            y = temp.second;
            if (grid[x][y] == '0') continue;
            grid[x][y] = '0';
            if (x >= 1 && grid[x - 1][y] == '1') q.push(make_pair(x - 1, y));
            if (x < m - 1 && grid[x + 1][y] == '1') q.push(make_pair(x + 1, y));
            if (y >= 1 && grid[x][y - 1] == '1') q.push(make_pair(x, y - 1));
            if (y < n - 1 && grid[x][y + 1] == '1') q.push(make_pair(x, y + 1));
        }
    }
};

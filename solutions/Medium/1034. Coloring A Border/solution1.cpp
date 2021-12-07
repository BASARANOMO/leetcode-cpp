typedef pair<int, int> pii;

class Solution {
public:
    void dfs(vector<vector<int>>& grid, int row, int col, vector<vector<int>>& visited, int color, vector<pii>& borders) {
        int m = grid.size(), n = grid[0].size();
        bool isBorder = false;
        int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for (int i = 0; i < 4; i++) {
            int x = row + dir[i][0], y = col + dir[i][1];
            if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] != color) isBorder = true;
            else if (!visited[x][y]) {
                visited[x][y] = 1;
                dfs(grid, x, y, visited, color, borders);
            }
        }
        if (isBorder) borders.emplace_back(row, col);
    }
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        vector<pii> borders;
        dfs(grid, row, col, visited, grid[row][col], borders);
        for (auto& [x, y] : borders) grid[x][y] = color;
        return grid;
    }
};
typedef pair<int,int> pii;

class Solution {
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        vector<pii> borders;
        int originalColor = grid[row][col];
        int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        queue<pii> q;
        q.emplace(row, col);
        visited[row][col] = 1;
        while (!q.empty()) {
            bool isBorder = false;
            pii& node = q.front();
            q.pop();
            int row = node.first, col = node.second;
            for (int i = 0; i < 4; i++) {
                int x = row + dir[i][0], y = col + dir[i][1];
                if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] != originalColor) isBorder = true;
                else if (!visited[x][y]) {
                    visited[x][y] = 1;
                    q.emplace(x, y);
                }
            }
            if (isBorder) borders.emplace_back(row, col);
        }
        for (auto& [x, y] : borders) grid[x][y] = color;
        return grid;
    }
};
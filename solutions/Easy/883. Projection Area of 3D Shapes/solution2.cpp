class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int sumTop = 0, sumFront = 0, sumSide = 0;
        int maxRow = 0, maxCol = 0;
        int n = grid.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0) sumTop++;
                maxRow = max(grid[i][j], maxRow);
                maxCol = max(grid[j][i], maxCol);
            }
            sumSide += maxRow;
            sumFront += maxCol;
            maxRow = 0;
            maxCol = 0;
        }
        return sumTop + sumFront + sumSide;
    }
};
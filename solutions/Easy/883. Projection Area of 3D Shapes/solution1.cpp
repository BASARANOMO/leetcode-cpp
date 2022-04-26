class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int sumTop = 0;
        int sumFront = 0;
        int sumSide = 0;
        int maxRow = 0;
        vector<int> maxCols(grid[0].size(), 0);
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] > 0) {
                    sumTop++;
                    maxRow = max(grid[i][j], maxRow);
                    maxCols[j] = max(grid[i][j], maxCols[j]);
                }
            }
            sumSide += maxRow;
            maxRow = 0;
        }
        for (int j = 0; j < grid[0].size(); j++) sumFront += maxCols[j];
        return sumTop + sumFront + sumSide;
    }
};
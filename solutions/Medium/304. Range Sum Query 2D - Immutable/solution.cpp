class NumMatrix {
private:
    vector<vector<int>> matSum;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (m > 0) {
            int n = matrix[0].size();
            matSum = vector<vector<int>>(m, vector<int>(n, 0));
            matSum[0][0] = matrix[0][0];
            for (int i = 1; i < m; i++) {
                matSum[i][0] = matSum[i-1][0] + matrix[i][0];
            }
            for (int j = 1; j < n; j++) {
                matSum[0][j] = matSum[0][j-1] + matrix[0][j];
            }
            for (int i = 1; i < m; i++) {
                for (int j = 1; j < n; j++) {
                    matSum[i][j] = matSum[i-1][j] + matSum[i][j-1] - matSum[i-1][j-1] + matrix[i][j];
                }
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        if (row1 == 0 && col1 == 0) return matSum[row2][col2];
        if (row1 == 0) {
            return matSum[row2][col2] - matSum[row2][col1-1];
        }
        if (col1 == 0) {
            return matSum[row2][col2] - matSum[row1-1][col2];
        }
        return matSum[row2][col2] - matSum[row1-1][col2] - matSum[row2][col1-1] + matSum[row1-1][col1-1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */

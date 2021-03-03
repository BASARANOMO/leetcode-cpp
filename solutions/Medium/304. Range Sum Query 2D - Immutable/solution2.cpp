class NumMatrix {
private:
    vector<vector<int>> matSum;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (m > 0) {
            int n = matrix[0].size();
            matSum = vector<vector<int>>(m+1, vector<int>(n+1, 0));
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    matSum[i+1][j+1] = matSum[i][j+1] + matSum[i+1][j] - matSum[i][j] + matrix[i][j];
                }
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return matSum[row2+1][col2+1] - matSum[row1][col2+1] - matSum[row2+1][col1] + matSum[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */

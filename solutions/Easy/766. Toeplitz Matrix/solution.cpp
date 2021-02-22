class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        if (m == 1) return true;
        for (int i = 0; i < matrix.size() - 1; i++) {
            for (int j = 0; j < matrix[0].size() - 1; j++) {
                if (matrix[i+1][j+1] != matrix[i][j]) return false;
            }
        }
        return true;
    }
};

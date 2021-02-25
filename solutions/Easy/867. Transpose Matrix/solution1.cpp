class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int temp;
        int m = matrix.size();
        int n = matrix[0].size();
        for (int i=0; i < n - m; i++) {
            matrix.push_back(vector<int>(m, 0));
        }
        if (m > n) {
            for (int i=0; i < m; i++) matrix[i].resize(m);
        }
        for (int i=0; i < m; i++) {
            for (int j=i+1; j < max(m, n); j++) {
                temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
            matrix[i].resize(m);
        }
        for (int i=0; i < m - n; i++) {
            matrix.pop_back();
        }
        return matrix;
    }
};

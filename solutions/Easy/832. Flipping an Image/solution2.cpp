class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int m = A.size();
        int temp;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m / 2; j++) {
                if (A[i][j] == A[i][m - 1 - j]) {
                    temp = 1 - A[i][j];
                    A[i][j] = 1 - A[i][m - 1 - j];
                    A[i][m - 1 - j] = temp;
                }
            }
            if (m&1) {
                A[i][m/2] = 1 - A[i][m/2];
            }
        }
        return A;
    }
};

#include <vector>
using namespace std;

class Solution {
public:
    int tribonacci(int n) {
        if (n == 0) return 0;
        if (n <= 2) return 1;
        vector<vector<long>> mat = {{0, 0, 1}, {1, 0, 1}, {0, 1, 1}};
        vector<vector<long>> ret = pow(mat, n - 2);
        return ret[0][2];
    }

    vector<vector<long>> pow(vector<vector<long>>& mat, int n) {
        vector<vector<long>> ret {{0, 1, 1}};
        while (n > 0) {
            if (n & 1) ret = multiply(ret, mat);
            n >>= 1;
            mat = multiply(mat, mat);
        }
        return ret;
    }

    vector<vector<long>> multiply(vector<vector<long>> a, vector<vector<long>> b) {
        int rows = a.size(), columns = b[0].size(), temp = b.size();
        vector<vector<long>> c(rows, vector<long>(columns));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                for (int k = 0; k < temp; k++) {
                    c[i][j] += a[i][k] * b[k][j];
                }
            }
        }
        return c;
    }
};
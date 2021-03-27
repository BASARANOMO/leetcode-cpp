class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n));
        int curr = 1;
        for (int round = 0; round < (n + 1) / 2; round++) {
            for (int i = round; i < n - round; i++) res[round][i] = curr++;
            for (int i = round + 1; i < n - round; i++) res[i][n - round - 1] = curr++;
            for (int i = n - round - 2; i >= round; i--) res[n - round - 1][i] = curr++;
            for (int i = n - round - 2; i > round; i--) res[i][round] = curr++;
        }
        return res;
    }
};

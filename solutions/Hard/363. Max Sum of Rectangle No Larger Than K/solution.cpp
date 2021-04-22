class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int res = INT_MIN;
        int m = matrix.size(), n = matrix[0].size();
        bool colIsLonger = m > n ? false : true;
        for (int i = 0; i < (colIsLonger ? m : n); i++) {
            vector<int> sum((colIsLonger ? n : m), 0);
            for (int j = i; j < (colIsLonger ? m : n); j++) {
                if (colIsLonger) for (int k = 0; k < n; k++) sum[k] += matrix[j][k];
                else for (int k = 0; k < m; k++) sum[k] += matrix[k][j];
                set<int> sumSet{0};
                int s = 0;
                for (int v : sum) {
                    s += v;
                    auto lb = sumSet.lower_bound(s - k);
                    if (lb != sumSet.end()) res = max(res, s - *lb);
                    sumSet.insert(s);
                }
            }
        }
        return res;
    }
};

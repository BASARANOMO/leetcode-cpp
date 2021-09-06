#include <vector>
#include <queue>
using namespace std;

auto cmp = [](vector<int>& a, vector<int>& b) {
    if (a[0] != b[0]) return a[0] < b[0];
    else return a[1] < b[1];
};
class Solution {
public:
    int binarySearch(vector<int>& row) {
        int n = row.size();
        int left = 0, right = n - 1, mid;
        while (left <= right) {
            mid = (left + right) >> 1;
            if (row[mid] == 0) right = mid - 1;
            else left = mid + 1;
        }
        return left;
    }
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> q(cmp);
        int m = mat.size();
        vector<int> cnt_idx(2);
        for (int i = 0; i < k; i++) {
            cnt_idx[0] = binarySearch(mat[i]);
            cnt_idx[1] = i;
            q.push(cnt_idx);
        }
        for (int i = k; i < m; i++) {
            cnt_idx[0] = binarySearch(mat[i]);
            cnt_idx[1] = i;
            if (q.top()[0] > cnt_idx[0]) {
                q.pop();
                q.push(cnt_idx);
            }
        }
        vector<int> ans(k);
        for (int i = 0; i < k; i++) {
            ans[k - i - 1] = q.top()[1];
            q.pop();
        }
        return ans;
    }
};
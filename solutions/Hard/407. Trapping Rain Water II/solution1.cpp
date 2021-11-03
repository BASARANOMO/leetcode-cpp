typedef pair<int,int> pii;

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        int n = heightMap[0].size();
        if (m <= 2 || n <= 2) return 0;
        priority_queue<pii, vector<pii>, greater<pii>> q;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            q.push({heightMap[i][0], i * n});
            visited[i][0] = true;
            q.push({heightMap[i][n - 1], i * n + n - 1});
            visited[i][n - 1] = true;
        }
        for (int j = 0; j < n; j++) {
            q.push({heightMap[0][j], j});
            visited[0][j] = true;
            q.push({heightMap[m - 1][j], (m - 1) * n + j});
            visited[m - 1][j] = true;
        }
        int ans = 0;
        vector<int> dirs = {-1, 0, 1, 0 , -1};
        while (!q.empty()) {
            pii curr = q.top();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nx = curr.second / n + dirs[i];
                int ny = curr.second % n + dirs[i + 1];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny]) {
                    if (heightMap[nx][ny] < curr.first) ans += curr.first - heightMap[nx][ny];
                    visited[nx][ny] = true;
                    q.push({max(heightMap[nx][ny], curr.first), nx * n + ny});
                }
            }
        }
        return ans;
    }
};
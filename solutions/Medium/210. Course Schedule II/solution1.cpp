class Solution {
private:
    vector<vector<int>> edges;
    vector<int> visited;
    vector<int> results;
    bool valid = true;
public:
    void dfs(int u) {
        visited[u] = 1;
        for (int v : edges[u]) {
            if (visited[v] == 0) { // not visited
                dfs(v);
                if (!valid) return;
            }
            else if (visited[v] == 1) { // currently visiting
                valid = false;
                return;
            }
        }
        results.push_back(u);
        visited[u] = 2; // visited
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        edges.resize(numCourses);
        visited.resize(numCourses);
        //results.resize(numCourses);
        for (const auto& info : prerequisites) {
            edges[info[1]].push_back(info[0]);
        }
        for (int i = 0; i < numCourses && valid; i++) {
            if (!visited[i]) dfs(i);
        }
        if (!valid) return {};
        reverse(results.begin(), results.end());
        return results;
    }
};
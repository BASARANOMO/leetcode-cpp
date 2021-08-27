#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    void dfs(vector<vector<int>>& graph, vector<int>& curr) {
        if (curr.back() == graph.size() - 1) {
            ans.push_back(curr);
            return;
        }
        for (int idx : graph[curr.back()]) {
            curr.push_back(idx);
            dfs(graph, curr);
            curr.pop_back();
        }

    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> curr {0};
        dfs(graph, curr);
        return ans;
    }
};
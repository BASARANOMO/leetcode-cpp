#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<int, vector<int>, less<int>> q_possible_projects;
        int n = profits.size(); // number of projects
        vector<pair<int, int>> arr_sort_by_capitals;
        for (int i = 0; i < n; i++) arr_sort_by_capitals.push_back({capital[i], profits[i]});
        sort(arr_sort_by_capitals.begin(), arr_sort_by_capitals.end());
        int idx = 0;
        for (int i = 0; i < k; i++) {
            // 1. put all possible projects (their profits) in the priority queue
            while (idx < n && arr_sort_by_capitals[idx].first <= w) q_possible_projects.push(arr_sort_by_capitals[idx++].second);
            // 2. invest in the most profitable project
            if (!q_possible_projects.empty()) {
                w += q_possible_projects.top();
                q_possible_projects.pop();
            } else break;  // 3. no projects to invest
        }
        return w;
    }
};
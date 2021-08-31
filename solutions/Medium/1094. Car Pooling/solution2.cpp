#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        // 1. sort by start location idx
        sort(trips.begin(), trips.end(), [](vector<int>& a, vector<int>& b) {return a[1] < b[1];});
        // 2. priority queue
        auto cmp = [](vector<int>& a, vector<int>& b) {
            return a[2] > b[2]; // the front of the queue contains the "last" element according to the weak ordering imposed by Compare
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> q(cmp);
        q.push(trips[0]);
        int cnt = trips[0][0];
        if (cnt > capacity) return false;
        for (int i = 1; i < trips.size(); i++) {
            // 3. getting off
            while (!q.empty() && q.top()[2] <= trips[i][1]) {
                cnt -= q.top()[0];
                q.pop();
            }
            // 4. boarding
            cnt += trips[i][0];
            q.push(trips[i]);
            if (cnt > capacity) return false;
        }
        return true;
    }
};
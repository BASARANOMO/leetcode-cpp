#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> smallestK(vector<int>& arr, int k) {
        if (k == 0) return vector<int>(0);
        priority_queue<int, vector<int>, less<int>> q;
        vector<int> ans(k);
        for (int i = 0; i < k; i++) {
            q.push(arr[i]);
        }
        for (int i = k; i < arr.size(); i++) {
            if (q.top() > arr[i]) {
                q.pop();
                q.push(arr[i]);
            }
        }
        for (int i = k - 1; i >= 0; i--) {
            ans[i] = q.top();
            q.pop();
        }
        return ans;
    }
};
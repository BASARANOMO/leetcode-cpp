#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> smallestK(vector<int>& arr, int k) {
        priority_queue<int, vector<int>, greater<int>> q;
        vector<int> ans(k);
        for (int i = 0; i < arr.size(); i++) {
            q.push(arr[i]);
        }
        for (int i = 0; i < k; i++) {
            ans[i] = q.top();
            q.pop();
        }
        return ans;
    }
};
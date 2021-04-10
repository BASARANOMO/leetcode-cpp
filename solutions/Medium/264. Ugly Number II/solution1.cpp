#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> factors{2, 3, 5};
        priority_queue<long, vector<long>, greater<long>> heap;
        unordered_set<long> seen;
        heap.push(1);
        seen.insert(1);
        long curr = 0;
        long next;
        for (int i = 0; i < n; i++) {
            curr = heap.top();
            heap.pop();
            for (int factor : factors) {
                next = factor * curr;
                if (!seen.count(next)) {
                    seen.insert(next);
                    heap.push(next);
                }
            }
        }
        return (int)curr;
    }
};
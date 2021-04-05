#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int n = answers.size();
        unordered_map<int, int> h;
        for (int i = 0; i < n; i++) {
            h[answers[i]]++;
        }
        int res = 0, temp;
        for (auto v : h) {
            if (v.first + 1 >= v.second) res += v.first + 1;
            else {
                temp = v.second / (v.first + 1);
                if (v.second % (v.first + 1) != 0) temp++;
                res += temp * (v.first + 1);
            }
        }
        return res;
    }
};
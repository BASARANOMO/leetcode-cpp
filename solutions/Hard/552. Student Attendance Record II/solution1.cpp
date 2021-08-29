#include <string>
using namespace std;

class Solution {
public:
    int ans;
    void dfs(int n, string& curr, int absent_cnt, int consequent_late_cnt) {
        if (curr.length() == n) {
            ans++;
            return;
        }
        if (absent_cnt < 1) {
            curr.push_back('A');
            dfs(n, curr, 1, 0);
            curr.pop_back();
        }
        if (consequent_late_cnt < 2) {
            curr.push_back('L');
            dfs(n, curr, absent_cnt, consequent_late_cnt + 1);
            curr.pop_back();
        }
        curr.push_back('P');
        dfs(n, curr, absent_cnt, 0);
        curr.pop_back();
    }
    int checkRecord(int n) {
        ans = 0;
        string curr = "";
        dfs(n, curr, 0, 0);
        return ans;
    }
};
#include <string>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int dp1 = 1, dp2 = 1, temp, val;
        int prev = s[0] - '0';
        if (prev == 0) return 0;
        for (int i = 1; i < s.size(); i++) {
            val = prev * 10 + (s[i] - '0');
            if (val == 0) return 0;
            else if (s[i] == '0' && val > 26) return 0;
            else if (val == 10 || val == 20) {
                temp = dp2;
                dp2 = dp1;
                dp1 = temp;
            }
            else if (val > 10 && val <= 26) {
                temp = dp1 + dp2;
                dp1 = dp2;
                dp2 = temp;
            } else dp1 = dp2;
            prev = s[i] - '0';
        }
        return dp2;
    }
};
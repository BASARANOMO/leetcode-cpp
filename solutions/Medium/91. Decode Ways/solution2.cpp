#include <string>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int dp1 = 1, dp2 = 1, temp;
        int prev = s[0] - '0';
        if (prev == 0) return 0;
        for (int i = 1; i < s.size(); i++) {
            temp = 0;
            if (s[i] != '0') temp += dp2;
            if (prev != 0 && prev * 10 + (s[i] - '0') <= 26) temp += dp1;
            dp1 = dp2;
            dp2 = temp;
            if (temp == 0) return 0;
            prev = s[i] - '0';
        }
        return dp2;
    }
};
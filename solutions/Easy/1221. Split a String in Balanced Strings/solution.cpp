class Solution {
public:
    int balancedStringSplit(string s) {
        int ans = 0;
        int l_cnt = 0, r_cnt = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'L') l_cnt++;
            else r_cnt++;
            if (l_cnt == r_cnt) {
                ans++;
                l_cnt = 0;
                r_cnt = 0;
            }
        }
        return ans;
    }
};
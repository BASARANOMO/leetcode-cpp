class Solution {
public:
    int maxPower(string s) {
        int ans = 1, cnt = 1;
        for (int i = 1; i < s.length(); i++) {
            if (s[i] == s[i - 1]) cnt++;
            else {
                ans = ans > cnt ? ans : cnt;
                cnt = 1;
            }
        }
        ans = ans > cnt ? ans : cnt;
        return ans;
    }
};
class Solution {
public:
    int maxPower(string s) {
        int left = 0, right = 0;
        int ans = 0;
        while (left < s.length()) {
            while (s[left] == s[right]) right++;
            ans = (right - left) > ans ? (right - left) : ans;
            left = right;
        }
        return ans;
    }
};
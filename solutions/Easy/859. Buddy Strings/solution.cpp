class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if (s.length() != goal.length()) return false;
        int n = s.length();

        if (s == goal) {
            vector<int> cnt_vec(26);
            for (int i = 0; i < n; i++) {
                cnt_vec[s[i] - 'a']++;
                if (cnt_vec[s[i] - 'a'] > 1) return true;
            }
        } else {
            int cnt = 0;
            vector<int> idx(2);
            for (int i = 0; i < n; i++) {
                if (s[i] != goal[i]) {
                    if (cnt >= 2) return false;
                    idx[cnt] = i;
                    cnt++;
                }
            }
            return (cnt == 2 && s[idx[0]] == goal[idx[1]] && s[idx[1]] == goal[idx[0]]);
        }
        return false;
    }
};
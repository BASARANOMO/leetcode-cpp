class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        // sliding window
        if (p.length() > s.length()) return {};
        vector<int> ans;
        int pLen = p.length();
        vector<int> cnt(26);
        for (int i = 0; i < pLen; i++) {
            cnt[s[i] - 'a']++;
            cnt[p[i] - 'a']--;
        }
        int diff = 0;
        for (int i = 0; i < 26; i++) if (cnt[i] != 0) diff++;
        if (diff == 0) ans.push_back(0);
        for (int i = 0; i < s.length() - pLen; i++) {
            cnt[s[i] - 'a']--;
            if (cnt[s[i] - 'a'] == 0) diff--;
            else if (cnt[s[i] - 'a'] == -1) diff++;
            cnt[s[i + pLen] - 'a']++;
            if (cnt[s[i + pLen] - 'a'] == 0) diff--;
            else if (cnt[s[i + pLen] - 'a'] == 1) diff++;
            if (diff == 0) ans.push_back(i + 1);
        }
        return ans;
    }
};
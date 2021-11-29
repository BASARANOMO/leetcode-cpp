class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        // sliding window
        if (p.length() > s.length()) return {};
        vector<int> ans;
        int pLen = p.length();
        vector<int> sCnt(26), pCnt(26);
        for (int i = 0; i < pLen; i++) {
            sCnt[s[i] - 'a']++;
            pCnt[p[i] - 'a']++;
        }
        if (sCnt == pCnt) ans.push_back(0);
        for (int i = 0; i < s.length() - pLen; i++) {
            sCnt[s[i] - 'a']--;
            sCnt[s[i + pLen] - 'a']++;
            if (sCnt == pCnt) ans.push_back(i + 1);
        }
        return ans;
    }
};
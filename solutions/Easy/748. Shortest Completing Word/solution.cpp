class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        array<int, 26> cnt{};
        for (char c : licensePlate) {
            if (isalpha(c)) cnt[tolower(c) - 'a']++;
        }
        int idx = -1;
        for (int i = 0; i < words.size(); i++) {
            array<int, 26> cnt_word{};
            for (char c : words[i]) cnt_word[c - 'a']++;
            bool ok = true;
            for (int j = 0; j < 26; j++) {
                if (cnt_word[j] < cnt[j]) {
                    ok = false;
                    break;
                }
            }
            if (ok && (idx < 0 || words[i].length() < words[idx].length())) idx = i;
        }
        return words[idx];
    }
};
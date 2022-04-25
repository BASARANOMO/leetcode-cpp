class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> bannedTable;
        for (auto &word : banned) bannedTable.emplace(word);
        unordered_map<string, int> cnts;
        int i = 0, maxCnt = 0, n = paragraph.size();
        string word;
        while (i < n) {
            int j = i;
            while (j < n && isalpha(paragraph[j])) {
                word.push_back(tolower(paragraph[j]));
                j++;
            } // get a word
            if (word != "" && !bannedTable.count(word)) {
                cnts[word]++;
                maxCnt = max(maxCnt, cnts[word]);
            }
            i = j + 1;
            word = "";
        }
        string ans;
        for (auto &[word, cnt] : cnts) if (cnts[word] == maxCnt) ans = word;
        return ans;
    }
};
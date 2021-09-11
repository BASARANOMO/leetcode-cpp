#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string blank(int n) {
        return string(n, ' ');
    }
    string join(vector<string>& words, int left, int right, string sep) {
        string s = words[left];
        for (int i = left + 1; i < right; i++) s += sep + words[i];
        return s;
    }
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int right = 0, n = words.size();
        while (true) {
            int left = right;
            int sumLen = 0;
            while (right < n && sumLen + words[right].length() + right - left <= maxWidth) sumLen += words[right++].length();
            
            // last row
            if (right == n) {
                string s = join(words, left, right, " ");
                ans.emplace_back(s + blank(maxWidth - s.length()));
                return ans;
            }

            // row having 1 word
            if (right - left == 1) ans.emplace_back(words[left] + blank(maxWidth - sumLen));
            else { // row having more than 1 word
                int avgSpaces = (maxWidth - sumLen) / (right - left - 1);
                int numExtraSpaces = (maxWidth - sumLen) % (right - left - 1); // num of words having extra 1 space
                string s1 = join(words, left, left + numExtraSpaces + 1, blank(avgSpaces + 1));
                string s2 = join(words, left + numExtraSpaces + 1, right, blank(avgSpaces));
                ans.emplace_back(s1 + blank(avgSpaces) + s2);
            }
        }
        return ans;
    }
};
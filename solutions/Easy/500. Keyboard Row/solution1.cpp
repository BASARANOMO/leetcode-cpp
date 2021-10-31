#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        unordered_map<char, int> whichRow;
        string s1 = "qwertyuiop";
        string s2 = "asdfghjkl";
        string s3 = "zxcvbnm";
        for (char c : s1) whichRow[c] = 1;
        for (char c : s2) whichRow[c] = 2;
        for (char c : s3) whichRow[c] = 3;
        vector<string> ans;
        for (string word : words) {
            int row = 0;
            for (char c : word) {
                if (row == 0) row = whichRow[tolower(c)];
                else if (row != whichRow[tolower(c)]) {
                    row = 0;
                    break;
                }
            }
            if (row != 0) ans.push_back(word);
        }
        return ans;
    }
};
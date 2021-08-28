#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        vector<char> chars;
        vector<int> idx;
        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            if (c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'i' || c == 'I' || c == 'o' || c == 'O' || c == 'u' || c == 'U') {
                chars.push_back(c);
                idx.push_back(i);
            }
        }
        for (int i = 0; i < idx.size(); i++) {
            s[idx[idx.size() - i - 1]] = chars[i];
        }
        return s;
    }
};
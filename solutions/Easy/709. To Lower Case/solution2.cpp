class Solution {
public:
    string toLowerCase(string s) {
        for (char& ch : s) {
            if (ch >= 65 && ch <= 90) ch |= 32;
        }
        return s;
    }
};
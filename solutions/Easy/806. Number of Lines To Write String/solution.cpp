class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int line = 1, width = 0;
        for (char &c : s) {
            int need = widths[c - 'a'];
            if (width + need > 100) {
                line++;
                width = need;
            } else width += need;
        }
        return vector<int> {line, width};
    }
};
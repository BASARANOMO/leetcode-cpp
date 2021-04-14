class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.length();
        vector<int> opened, pair(n);
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') opened.push_back(i);
            if (s[i] == ')') {
                int j = opened.back();
                opened.pop_back();
                pair[i] = j;
                pair[j] = i;
            }
        }
        string res;
        for (int i = 0, direction = 1; i < n; i += direction) {
            if (s[i] == '(' || s[i] == ')') {
                i = pair[i];
                direction = -direction;
            } else res += s[i];
        }
        return res;
    }
};

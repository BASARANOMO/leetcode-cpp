class Solution {
public:
    bool checkValidString(string s) {
        int minCnt = 0, maxCnt = 0;
        int n = s.length();
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                minCnt++;
                maxCnt++;
            } else if (s[i] == ')') {
                if (maxCnt == 0) return false;
                minCnt = max(minCnt - 1, 0);
                maxCnt--;
            } else {
                minCnt = max(minCnt - 1, 0);
                maxCnt++;                
            }
        }
        return minCnt == 0;
    }
};
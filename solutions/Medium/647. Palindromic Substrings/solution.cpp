class Solution {
public:
    int countSubstrings(string s) {
        string S = "$#";
        for (char ch : s) {
            S += ch;
            S += '#';
        }
        S += '!';
        int n = S.size();

        vector<int> rad(n - 2);
        int rMax = 0, idxMax = 0, ans = 0;
        for (int i = 1; i < n - 1; i++) {
            rad[i - 1] = (i <= rMax) ? min(rad[2 * idxMax - i - 1], rMax - i + 1) : 1;
            while (S[i + rad[i - 1]] == S[i - rad[i - 1]]) rad[i - 1]++;
            if (i + rad[i - 1] - 1 > rMax) {
                idxMax = i;
                rMax = i + rad[i - 1] - 1;
            }
            ans += (rad[i - 1] / 2);
        }
        return ans;
    }
};

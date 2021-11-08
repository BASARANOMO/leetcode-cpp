class Solution {
public:
    string getHint(string secret, string guess) {
        vector<int> cntS(10), cntG(10);
        int bulls = 0, cows = 0;
        for (int i = 0; i < secret.size(); i++) {
            if (guess[i] == secret[i]) bulls++;
            else {
                cntS[secret[i] - '0']++;
                cntG[guess[i] - '0']++;
            }
        }
        for (int i = 0; i < 10; i++) {
            cows += min(cntS[i], cntG[i]);
        }
        string ans = to_string(bulls) + "A" + to_string(cows) + "B";
        return ans;
    }
};
class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char, int> target;
        vector<int> missedIdx;
        int bulls = 0;
        for (int i = 0; i < secret.size(); i++) {
            if (guess[i] == secret[i]) bulls++;
            else {
                target[secret[i]]++;
                missedIdx.push_back(i);
            }
        }
        int cows = 0;
        for (int i : missedIdx) {
            if (target[guess[i]] > 0) {
                cows++;
                target[guess[i]]--;
            }
        }
        string ans = to_string(bulls) + "A" + to_string(cows) + "B";
        return ans;
    }
};
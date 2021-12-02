class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<int> index(n);
        iota(index.begin(), index.end(), 0);
        sort(index.begin(), index.end(), [&](int i, int j) {
            return score[i] > score[j];
        });
        vector<string> ans(n);
        ans[index[0]] = "Gold Medal";
        if (n > 1) ans[index[1]] = "Silver Medal";
        if (n > 2) ans[index[2]] = "Bronze Medal";
        for (int i = 3; i < n; i++) ans[index[i]] = to_string(i + 1);
        return ans;
    }
};
class Solution {
public:
    bool dfs(vector<int>& matchsticks, int idx, int target, vector<int>& sides) {
        if (idx == matchsticks.size()) {
            if (sides[0] == sides[1] && sides[1] == sides[2] && sides[2] == sides[3]) return true;
            return false;
        }
        int curr = matchsticks[idx];
        for (int i = 0; i < 4; i++) {
            if (sides[i] + curr <= target) {
            sides[i] += curr;
            if (dfs(matchsticks, idx + 1, target, sides)) return true;
            sides[i] -= curr;
            }
        }
        return false;
    }

    bool makesquare(vector<int>& matchsticks) {
        int n = matchsticks.size();
        if (n == 0) return false;
        int total = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (total % 4 != 0) return false;
        sort(matchsticks.begin(), matchsticks.end(), greater());
        vector<int> sides(4);
        return dfs(matchsticks, 0, total / 4, sides);
    }
};
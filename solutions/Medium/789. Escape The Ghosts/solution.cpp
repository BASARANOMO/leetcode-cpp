#include <vector>
using namespace std;

class Solution {
public:
    int manhattanDistance(vector<int>& p1, vector<int> p2) {
        return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]);
    }
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        vector<int> source {0, 0};
        int dist = manhattanDistance(source, target);
        int ghostDist;
        for (int i = 0; i < ghosts.size(); i++) {
            ghostDist = manhattanDistance(ghosts[i], target);
            if (ghostDist <= dist) return false;
        }
        return true;
    }
};
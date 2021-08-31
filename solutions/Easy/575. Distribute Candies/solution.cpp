#include <set>
#include <vector>
using namespace std;

class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        set<int> h;
        for (int i = 0; i < candyType.size(); i++) {
            h.insert(candyType[i]);
        }
        return h.size() > candyType.size() / 2 ? candyType.size() / 2 : h.size();
    }
};
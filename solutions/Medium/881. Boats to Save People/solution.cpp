#include <vector>
using namespace std;

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int left = 0, right = people.size() - 1;
        int res = 0;
        while (right > left) {
            if (people[left] + people[right] > limit) {
                right--;
            } else {
                right--;
                left++;
            }
            res++;
        }
        return res;
    }
};
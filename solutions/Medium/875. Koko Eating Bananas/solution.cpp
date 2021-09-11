class Solution {
public:
    bool possible(vector<int>& piles, int h, int k) {
        int hours = 0;
        for (int i = 0; i < piles.size(); i++) {
            hours += (piles[i] - 1) / k + 1;
        }
        return hours <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = 1e9, mid;
        while (low < high) {
            mid = (low + high) >> 1;
            if (possible(piles, h, mid)) high = mid;
            else low = mid + 1;
        }
        return low;
    }
};
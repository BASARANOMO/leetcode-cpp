#include <algorithm>
using namespace std;

class Solution {
public:
    bool judgeSquareSum(int c) {
        long a = 0, b = sqrt(c), sum;
        while (a <= b) {
            sum = a * a + b * b;
            if (sum == c) return true;
            else if (sum < c) a++;
            else b--;
        }
        return false;
    }
};
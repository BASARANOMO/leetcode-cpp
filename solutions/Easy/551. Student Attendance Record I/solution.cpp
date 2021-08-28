#include <string>
using namespace std;

class Solution {
public:
    bool checkRecord(string s) {
        int n = s.length(), absent_count = 0, consequent_late_count = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'A') {
                absent_count++;
                consequent_late_count = 0;
            }
            else if (s[i] == 'L') consequent_late_count++;
            else consequent_late_count = 0;
            if (absent_count >= 2 || consequent_late_count >= 3) return false;
        }
        return true;
    }
};
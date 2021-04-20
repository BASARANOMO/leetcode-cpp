#include <string>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.size(), n = needle.size();
        if (m < n) return -1;
        if (n == 0) return 0;
        int prev = 0, pos1 = 0, pos2 = 0;
        while (pos1 < m) {
            if (haystack[pos1] == needle[pos2]) {
                if (pos2 == 0) prev = pos1;
                pos1++;
                pos2++;
            } else {
                // pos1 go back
                pos1 = ++prev;
                pos2 = 0;
            }
            if (pos2 == n) return prev;
        }
        return -1;
    }
};
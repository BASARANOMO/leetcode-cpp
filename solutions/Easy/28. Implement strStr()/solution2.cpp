#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.size(), n = needle.size();
        unordered_map<char, int> shift;
        for (int i = 0; i < n; i++) shift[needle[i]] = n - i;

        int i = 0;
        while (i <= m - n) {
            if (haystack.substr(i, n) == needle) return i;
            else {
                if (shift.find(haystack[i + n]) != shift.end()) i += shift[haystack[i + n]];
                else i += n + 1;
            }
        }
        return -1;
    }
};
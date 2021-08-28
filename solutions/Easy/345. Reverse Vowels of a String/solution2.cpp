#include <string>
using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        int n = s.length();
        int left = 0, right = n - 1;
        while (left < right) {
            while (left < n && (s[left] != 'a' && s[left] != 'A' && s[left] != 'e' && s[left] != 'E' && s[left] != 'i' && s[left] != 'I' && s[left] != 'o' && s[left] != 'O' && s[left] != 'u' && s[left] != 'U')) left++;
            while (right > 0 && (s[right] != 'a' && s[right] != 'A' && s[right] != 'e' && s[right] != 'E' && s[right] != 'i' && s[right] != 'I' && s[right] != 'o' && s[right] != 'O' && s[right] != 'u' && s[right] != 'U')) right--;
            if (left < right) {
                swap(s[left], s[right]);
                left++;
                right--;
            }
        }
        return s;
    }
};
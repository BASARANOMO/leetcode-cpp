#include <string>
using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        int m = num1.size(), n = num2.size();
        int carry = 0, curr;
        string res = "";
        char ch;
        int x, y;
        while (m > 0 || n > 0 || carry == 1) {
            x = m > 0 ? num1[m - 1] - '0' : 0;
            y = n > 0 ? num2[n - 1] - '0' : 0;
            curr = x + y + carry;
            carry = 0;
            if (curr / 10 > 0) {
                carry = 1;
                curr = curr % 10;
            }
            ch = '0' + curr;
            res = ch + res;
            m--;
            n--;
        }
        return res;
    }
};
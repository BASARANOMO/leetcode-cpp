#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
        int cnt = 0, anchor = 0;
        bool secondPart = false;
        stack<int> stk;
        for (int i = 0; i < s.length() + 1; i++) {
            if (stk.size() == k || i == s.length()) {
                while (!stk.empty()) {
                    s[anchor++] = stk.top();
                    stk.pop();
                }
                secondPart = true;
            } 
            if (secondPart) {
                cnt--;
                anchor++;
            }
            else {
                stk.push(s[i]);
                cnt++;
            }
            if (cnt == 0) secondPart = false;
        }
        return s;
    }
};
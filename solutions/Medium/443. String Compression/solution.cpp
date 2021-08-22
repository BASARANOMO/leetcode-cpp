#include <vector>
using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        int idxCurr = 0, cnt = 0;
        for (int i = 0; i < chars.size() + 1; i++) {
            if (i == chars.size() || chars[idxCurr] != chars[i]) {
                if (cnt > 1) {
                    int anchor = idxCurr + 1;
                    while (cnt != 0) {
                        chars[++idxCurr] = (cnt % 10 + '0');
                        cnt = cnt / 10;
                    }
                    idxCurr++;
                    reverse(&chars[anchor], &chars[idxCurr]);
                } else idxCurr++;
                if (i != chars.size()) {
                chars[idxCurr] = chars[i];
                cnt = 1;
                }
            } else cnt += 1;
        }
        return idxCurr;
    }
};
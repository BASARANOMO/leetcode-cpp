class Solution {
public:
    string removeDuplicates(string S) {
        int len = S.size();
        int left = 0, right = 1;
        while (left < len) {
            if (S[left] == S[right]) {
                S.erase(left, 2);
                left = max(0, left - 1);
                right = max(left + 1, right - 1);
                len -= 2;
            } else {
                left++;
                right++;
            }
        }
        return S;
    }
};

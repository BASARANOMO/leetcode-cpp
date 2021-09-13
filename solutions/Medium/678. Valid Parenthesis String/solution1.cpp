class Solution {
public:
    bool checkValidString(string s) {
        stack<int> leftParenthesisIdx;
        stack<int> asterIdx;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') leftParenthesisIdx.push(i);
            else if (s[i] == ')') {
                if (!leftParenthesisIdx.empty()) leftParenthesisIdx.pop();
                else {
                    if (!asterIdx.empty()) asterIdx.pop();
                    else return false;
                }
            } else asterIdx.push(i);
        }
        while (!leftParenthesisIdx.empty() && !asterIdx.empty()) {
            if (leftParenthesisIdx.top() < asterIdx.top()) {
                leftParenthesisIdx.pop();
                asterIdx.pop();
            } else return false;
        }
        return leftParenthesisIdx.empty();
    }
};
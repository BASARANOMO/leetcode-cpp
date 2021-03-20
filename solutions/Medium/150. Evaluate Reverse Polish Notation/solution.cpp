class Solution {
public:
    bool isNumber(string& token) {
        return !(token == "+" || token == "-" || token == "*" || token == "/");
    }

    int evalRPN(vector<string>& tokens) {
        int left, right;
        stack<int> nums;
        int n = tokens.size();
        for (int i = 0; i < n; i++) {
            if (isNumber(tokens[i])) {
                nums.push(stoi(tokens[i]));
            } else {
                right = nums.top();
                nums.pop();
                left = nums.top();
                nums.pop();
                if (tokens[i] == "+") nums.push(left + right);
                else if (tokens[i] == "-") nums.push(left - right);
                else if (tokens[i] == "*") nums.push(left * right);
                else nums.push(left / right);
            }
        }
        return nums.top();
    }
};

class Solution {
public:
    string removeDuplicates(string S) {
        int len = S.size();
        string res;
        for (char c : S) {
            if (!res.empty() && c == res.back()) res.pop_back();
            else res.push_back(c);
        }
        return res;
    }
};

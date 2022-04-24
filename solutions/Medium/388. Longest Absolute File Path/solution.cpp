class Solution {
public:
    int lengthLongestPath(string input) {
        int n = input.size();
        int pos = 0;
        int ans = 0;
        stack<int> st;

        while (pos < n) {
            /* check current depth */
            int depth = 1;
            while (pos < n && input[pos] == '\t') {
                pos++;
                depth++;
            }
            /* get length of subdirectory/file */   
            int len = 0; 
            bool isFile = false;     
            while (pos < n && input[pos] != '\n') {
                if (input[pos] == '.') {
                    isFile = true;
                }
                len++;
                pos++;
            }
            /* skip \n */
            pos++;

            while (st.size() >= depth) {
                st.pop();
            }
            if (!st.empty()) { // length (with subdirectories)
                len += st.top() + 1;
            }
            if (isFile) { // if file, check whether its length is max
                ans = max(ans, len);
            } else {
                st.emplace(len);
            }
        }
        return ans;
    }
};

#include <limits.h>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int minDiffInBST(TreeNode* root) {
        // inorder traversal
        int res = INT_MAX;
        int last_elem = -1;
        stack<TreeNode*> stk;
        while (root || !stk.empty()) {
            while (root) {
                stk.push(root);
                root = root->left;
            }
            root = stk.top();
            stk.pop();
            if (last_elem != -1) res = min(root->val - last_elem, res);
            last_elem = root->val;
            root = root->right;
        }
        return res;
    }
};

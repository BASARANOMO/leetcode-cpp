#include <limits.h>
using namespace std;

class Solution {
    int res;
    int last_elem;

public:
    void recursiveInorderTraversal(TreeNode* root) {
        if (!root) return;
        recursiveInorderTraversal(root->left);
        if (last_elem >= 0) res = min(res, root->val - last_elem);
        last_elem = root->val;
        recursiveInorderTraversal(root->right);
    }
    int getMinimumDifference(TreeNode* root) {
        // inorder traversal
        res = INT_MAX;
        last_elem = -1;
        recursiveInorderTraversal(root);
        return res;
    }
};

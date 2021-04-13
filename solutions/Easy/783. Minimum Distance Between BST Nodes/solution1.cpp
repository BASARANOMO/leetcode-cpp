#include <limits.h>
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
    int res;
    int last_elem;
public:
    void recursiveInorderTraversal(TreeNode* root) {
        if (!root) return;
        recursiveInorderTraversal(root->left);
        if (last_elem != -1) res = min(res, root->val - last_elem);
        last_elem = root->val;
        recursiveInorderTraversal(root->right);
    }
    int minDiffInBST(TreeNode* root) {
        // inorder traversal
        res = INT_MAX;
        last_elem = -1;
        recursiveInorderTraversal(root);
        return res;
    }
};

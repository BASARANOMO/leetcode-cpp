/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return util(root, LONG_MAX, LONG_MIN);
    }

    bool util(TreeNode* T, long upperBound, long lowerBound) {
        if (T == NULL) return true;
        if (T->val <= lowerBound || T->val >= upperBound) return false;
        return util(T->left, T->val, lowerBound) && util(T->right, upperBound, T->val);
    }
};

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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        dfs(root, res, "");
        return res;
    }

    void dfs(TreeNode* T, vector<string>& res, string curr) {
        if (T != nullptr) {
            curr += to_string(T->val);
            if (!T->left && !T->right) {
                res.push_back(curr);
            }
            else {
                dfs(T->left, res, curr+"->");
                dfs(T->right, res, curr+"->");
            }
        }
    }
};

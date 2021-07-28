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
    int findSecondMinimumValue(TreeNode* root) {
        if (root == nullptr) return -1;
        int min_val = root->val;
        int temp_left = min_val, temp_right = min_val;
        if (root->left != nullptr) {
            temp_left = (root->left->val != min_val) ? root->left->val : findSecondMinimumValue(root->left);
            temp_right = (root->right->val != min_val) ? root->right->val : findSecondMinimumValue(root->right);
            if (temp_left == -1) return temp_right;
            else if (temp_right == -1) return temp_left;
            else return min(temp_left, temp_right);
        } else return -1;
    }
};

using namespace std;
/**
 * Definition for a binary tree node.
 **/
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
private:
    int res;
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        res = 0;
        recursiveCompute(root, low, high);
        return res;
    }

    void recursiveCompute(TreeNode* root, int low, int high) {
        if (!root) return;
        if (root->val < low) recursiveCompute(root->right, low, high);
        else if (root->val > high) recursiveCompute(root->left, low, high);
        else {
            res += root->val;
            recursiveCompute(root->left, low, high);
            recursiveCompute(root->right, low, high);
        }
    }
};
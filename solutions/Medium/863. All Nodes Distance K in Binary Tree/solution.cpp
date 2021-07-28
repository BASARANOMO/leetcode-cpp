/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<int, TreeNode*> parents;
    vector<int> ans;

    void findParents(TreeNode* node) {
        if (node->left != nullptr) {
            parents[node->left->val] = node;
            findParents(node->left);
        }
        if (node->right != nullptr) {
            parents[node->right->val] = node;
            findParents(node->right);
        }
    }

    void findAnswers(TreeNode* node, TreeNode* from, int depth, int k) {
        if (node == nullptr) return;
        if (depth == k) {
            ans.push_back(node->val);
            return;
        }
        if (node->left != from) findAnswers(node->left, node, depth+1, k);
        if (node->right != from) findAnswers(node->right, node, depth+1, k);
        if (parents[node->val] != from) findAnswers(parents[node->val], node, depth+1, k);
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        findParents(root);
        findAnswers(target, nullptr, 0, k);
        return ans;
    }
};

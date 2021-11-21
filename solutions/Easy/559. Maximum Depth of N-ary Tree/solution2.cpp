/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) {
        if (root == NULL) return 0;
        queue<Node*> q;
        q.push(root);
        int res = 0;
        while (!q.empty()) {
            int size = q.size();
            while (size > 0) {
                Node* curr = q.front();
                q.pop();
                for (auto child : curr->children) {
                    q.push(child);
                }
                size--;
            }
            res++;
        }
        return res;
    }
};
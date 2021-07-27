class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;
        unordered_map<Node*, Node*> cachedNode;
        Node* curr = head;
        while (curr != nullptr) {
            cachedNode[curr] = new Node(curr->val);
            curr = curr->next;
        }
        curr = head;
        while (curr != nullptr) {
            cachedNode[curr]->next = cachedNode[curr->next];
            cachedNode[curr]->random = cachedNode[curr->random];
            curr = curr->next;
        }
        return cachedNode[head];
    }
};
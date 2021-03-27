/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;
        int n = 1;
        ListNode* fast = head;
        while (fast->next) {
            fast = fast->next;
            n++;
        }
        k %= n;
        if (k == 0) return head;
        fast = head;
        ListNode* slow = head;
        for (int i = 0; i < k; i++) {
            fast = fast->next;
        }
        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }

        auto nHead = slow->next;
        slow->next = nullptr;
        fast->next = head;
        return nHead;
    }
};
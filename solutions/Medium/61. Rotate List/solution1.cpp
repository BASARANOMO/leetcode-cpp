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
        ListNode* iter = head;
        while (iter->next) {
            iter = iter->next;
            n++;
        }
        int add = n - k % n;
        if (add == n) return head;
        iter->next = head;
        while (add--) {
            iter = iter->next;
        }
        ListNode* res = iter->next;
        iter->next = nullptr;
        return res;
    }
};
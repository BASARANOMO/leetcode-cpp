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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        head->next = l1;
        ListNode* prev = head;
        int carry = 0, temp = 0;
        bool changed = false;
        while (l1 || l2) {
            if (l1) temp += l1->val;
            if (l2) temp += l2->val;
            temp += carry;
            carry = temp / 10;
            temp %= 10;
            if (l1) {
                l1->val = temp;
                l1 = l1->next;
            } else {
                if (!changed) {
                    prev->next = l2;
                    changed = true;
                }
            }
            if (l2) {
                if (changed) l2->val = temp;
                l2 = l2->next;
            }
            prev = prev->next;
            temp = 0;
        }
        if (carry) prev->next = new ListNode(carry);
        return head->next;
    }
};

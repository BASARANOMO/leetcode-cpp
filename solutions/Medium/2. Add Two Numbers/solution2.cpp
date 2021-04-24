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
        while (l1 && l2) {
            temp += l1->val + l2->val + carry;
            carry = temp / 10;
            temp %= 10;
            l1->val = temp;
            temp = 0;
            l1 = l1->next;
            l2 = l2->next;
            prev = prev->next;
        }
        if (l2) l1 = l2;
        prev->next = l1;
        while (l1) {
            temp += l1->val + carry;
            carry = temp / 10;
            temp %= 10;
            l1->val = temp;
            temp = 0;
            l1 = l1->next;
            prev = prev->next;
        }
        if (carry) prev->next = new ListNode(carry);
        return head->next;
    }
};

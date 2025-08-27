class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        int carry = 0;
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;

        while (p1 != NULL || p2 != NULL || carry) {
            int x = (p1 != NULL ? p1->val : 0);
            int y = (p2 != NULL ? p2->val : 0);

            int sum = x + y + carry;
            carry = sum / 10;
            int digit = sum % 10;
            curr->next = new ListNode(digit);
            curr = curr->next;

            if (p1 != NULL) p1 = p1->next;
            if (p2 != NULL) p2 = p2->next;
        }

        return dummy->next; 
    }
};

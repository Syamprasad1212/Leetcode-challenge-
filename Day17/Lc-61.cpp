class Solution {
public:
    ListNode* moveSteps(ListNode* head, int steps) {
        while (steps-- > 0 && head != nullptr) {
            head = head->next;
        }
        return head;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;

        ListNode* tail = head;
        int len = 1;
        while (tail->next != nullptr) {
            tail = tail->next;
            len++;
        }

        k %= len;
        if (k == 0) return head;

        tail->next = head;

        ListNode* newTail = moveSteps(head, len - k - 1);
        ListNode* newHead = newTail->next;

        newTail->next = nullptr;

        return newHead;
    }
};

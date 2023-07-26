class Solution {
public:
    ListNode* reverse(ListNode* curr, ListNode* prev) {
        if (curr == NULL) {
            return prev;
        }

        ListNode* forward = curr->next;
        curr->next = prev;
        return reverse(forward, curr);
    }

    ListNode* reverseList(ListNode* head) {
        return reverse(head, NULL);
    }
};

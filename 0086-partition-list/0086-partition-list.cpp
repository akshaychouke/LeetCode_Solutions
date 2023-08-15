class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* lessHead = new ListNode(0);
        ListNode* lessPtr = lessHead;
        ListNode* greaterHead = new ListNode(0);
        ListNode* greaterPtr = greaterHead;

        ListNode* curr = head;

        while (curr != NULL) {
            if (curr->val < x) {
                lessPtr->next = curr;
                lessPtr = lessPtr->next;
            } else {
                greaterPtr->next = curr;
                greaterPtr = greaterPtr->next;
            }
            curr = curr->next;
        }

        lessPtr->next = greaterHead->next;
        greaterPtr->next = NULL;

        return lessHead->next;
    }
};

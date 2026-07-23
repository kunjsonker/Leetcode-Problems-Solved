class Solution {
public:
    void reorderList(ListNode* head) {

        if (head == NULL || head->next == NULL)
            return;

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* second = slow->next;
        slow->next = NULL;

        ListNode* prev = NULL;
        ListNode* curr = second;

        while (curr != NULL) {
            ListNode* nextt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextt;
        }

        ListNode* first = head;
        ListNode* secondHalf = prev;

        while (secondHalf != NULL) {
            ListNode* t1 = first->next;
            ListNode* t2 = secondHalf->next;

            first->next = secondHalf;
            secondHalf->next = t1;

            first = t1;
            secondHalf = t2;
        }
    }
};

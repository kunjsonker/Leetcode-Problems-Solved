class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        int cnt = 0;
        ListNode* temp = head;

        while (temp) {
            cnt++;
            temp = temp->next;
        }

        // Remove the first node
        if (cnt == n) {
            return head->next;
        }

        temp = head;

        // Move to the node before the one to delete
        for (int i = 1; i < cnt - n; i++) {
            temp = temp->next;
        }

        temp->next = temp->next->next;

        return head;
    }
};

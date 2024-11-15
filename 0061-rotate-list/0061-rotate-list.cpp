class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL || k == 0) return head;

        // Step 1: Count the number of nodes in the list
        int count = 0;
        ListNode* curr = head;
        while (curr != NULL) {
            count++;
            curr = curr->next;
        }

        // Step 2: Calculate effective rotations
        k = k % count;
        if (k == 0) return head;

        // Step 3: Find the new head position (count - k)
        int index = count - k;
        ListNode* newTail = head;
        for (int i = 1; i < index; i++) {
            newTail = newTail->next;
        }

        // Step 4: Set new head and break the list
        ListNode* newHead = newTail->next;
        newTail->next = NULL;

        // Step 5: Find the end of the rotated part and link it to the original head
        ListNode* tail = newHead;
        while (tail->next != NULL) {
            tail = tail->next;
        }
        tail->next = head;

        return newHead;
    }
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* curr = head;
        
        // Check if there are at least two nodes to swap
        while (curr != NULL && curr->next != NULL) {
            // Swap values of the current pair
            int temp = curr->val;
            curr->val = curr->next->val;
            curr->next->val = temp;

            // Move to the next pair
            curr = curr->next->next;
        }

        return head;
    }
};

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = 1;
        if(head==NULL) return head;
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = head;
        ListNode* curr = head;
        while(count!=n){
            count++;
            fast = fast->next;

        }
        if (fast->next == NULL) {
            ListNode* temp = head;
            head = head->next; 
            delete temp;  
            return head;
        }
        while(fast->next!=NULL){
            prev = slow;
            slow = slow->next;
            fast = fast->next;
        }
        prev->next = slow->next;
        slow->next = NULL;
        return head;
    }
};
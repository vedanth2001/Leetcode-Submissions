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
    ListNode* reverseList(ListNode* head){
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;
        while(curr!=NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverseList(l1);
        l2 = reverseList(l2);
        ListNode* dummy = new ListNode(-1);
        int carry = 0;
        ListNode* head1 = l1;
        ListNode* head2 = l2;
        ListNode* curr = dummy;
        while(head1 || head2){
            int sum = carry;
            if(head1) sum += head1->val;
            if(head2) sum += head2->val;
            ListNode* next = new ListNode(sum%10);
            carry = sum/10;
            curr->next = next;
            curr = curr->next;
            if(head1) head1 = head1->next;
            if(head2) head2 = head2->next;
        }
        if(carry!=0){
            curr->next = new ListNode(carry);
        }
        return reverseList(dummy->next);
    }
};
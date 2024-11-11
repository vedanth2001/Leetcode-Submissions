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
            curr->next=prev;

            prev = curr;
            curr = next;
        }
        return prev;
    }
    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;
        int result = INT_MIN;
        while(fast!=NULL && fast->next!=NULL){
            prev = slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* newHead = reverseList(prev->next);
        prev->next = NULL;
        while(head!=NULL){
            int x = head->val+newHead->val;
            if( x > result)
            result = x;

            head = head->next;
            newHead = newHead -> next;
        }
        return result;
    }
};
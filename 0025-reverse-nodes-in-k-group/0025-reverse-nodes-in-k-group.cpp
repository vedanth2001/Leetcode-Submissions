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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int count = 0;
        ListNode* curr = head;
        if (!head || k == 1) return head;
        while(curr!=NULL){
            count++;
            curr = curr->next;
        }
        if(count<k) return head;
        curr = head;
        ListNode* next = NULL;
        ListNode* prev = NULL;
        count = 0;
        while(curr!=NULL && count<k){
            count++;
            next = curr->next;
            curr->next = prev;

            prev = curr;
            curr = next;
        }
        if(next!=NULL){
            head->next = reverseKGroup(curr, k);
        }
        return prev;
    }
};
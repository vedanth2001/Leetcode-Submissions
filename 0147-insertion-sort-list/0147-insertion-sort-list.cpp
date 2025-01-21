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
    ListNode* processSorted(ListNode* &sorted, ListNode* head){
         if(sorted == NULL || head->val < sorted->val){
            head->next = sorted;
            sorted = head;
        }
        else{
            ListNode* curr = sorted;
            while(curr->next!=NULL && curr->next->val < head->val){
                curr = curr->next;
            }
            head->next = curr->next;
            curr->next = head;

        }
        return sorted;
    }
    ListNode* insertionSortList(ListNode* head) {
        ListNode* sorted = NULL;
        ListNode* curr = head;
        while(curr!=NULL){
            ListNode* nextNode = curr->next; 
            curr->next = NULL; 
            sorted = processSorted(sorted, curr); 
            curr = nextNode;
        }
        return sorted;
    }
};
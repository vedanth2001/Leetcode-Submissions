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
    ListNode* swapNodes(ListNode* head, int k) {
        if(head==NULL) return NULL;
        ListNode* node1 = NULL;
        ListNode* node2 = head;
        ListNode* curr = head;
        int count = 1;
        while(curr!=NULL && count!=k){
            curr = curr->next;
            count++;
        }
        node1 = curr;
        int value = curr->val;
        while(curr->next!=NULL){
            curr= curr->next;
            node2 = node2->next;
        }
        int value2 = node2->val;
        node1->val = value2;
        node2->val = value;
        return head;
    }
};
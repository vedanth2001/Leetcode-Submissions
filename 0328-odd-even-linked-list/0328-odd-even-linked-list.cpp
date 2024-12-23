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
    ListNode* oddEvenList(ListNode* head) {
        ListNode * odd=head;
        if(head==NULL) return head;
        ListNode * even=head->next;
        if(odd==NULL || even == NULL) return head;
        ListNode * ptr1=odd;
        ListNode* ptr2=even;
        while(ptr2!=NULL && ptr2->next!=NULL){
            ptr1->next=ptr1->next->next;
            ptr2->next=ptr2->next->next;
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }
        ptr1->next=even;
        return odd;

    }
};
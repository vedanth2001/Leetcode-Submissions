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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL) return list2;
        if(list2==NULL) return list1;
        ListNode* head = NULL;
        ListNode* tail = NULL;
        if(list1->val>=list2->val){
            tail = list2;
            head = tail;
            list2=list2->next;   
        }
        else{
            tail = list1;
            head = tail;
            list1=list1->next;
        }
        while(list1!=NULL && list2!=NULL){
            if(list1->val>=list2->val){
                tail->next = list2;
                tail=tail->next;
                list2=list2->next;
            }
            else{
                tail->next=list1;
                tail=tail->next;
                list1=list1->next;
            }
        }
        if(list1==NULL){
            tail->next=list2;
        }
        else if(list2==NULL){
            tail->next=list1;
        }
        return head;
    }
};
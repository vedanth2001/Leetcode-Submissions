/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int countA = 0;
        int countB = 0;
        int diff = 0;
        ListNode* curr = headA;
        while(curr!=NULL) {
            countA++;
            curr = curr->next;
        }
        curr = headB;
        while(curr!=NULL){
            countB++;
            curr = curr->next;
        }
        ListNode* currX;
        if(countA>countB){
            curr = headA;
            currX = headB;
        }
        else{curr = headB;
              currX = headA;
            }

        diff = abs(countA-countB);

        while(diff!=0){
            curr = curr->next;
            diff--;
        }
        while(curr!=NULL){
            if(curr==currX) return curr;
            curr=curr->next;
            currX=currX->next;
        }
        return NULL;
    }
};
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
    ListNode* merge(ListNode* l1, ListNode* l2){
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;

        if(l1->val<l2->val){
            l1->next = merge(l1->next, l2);
            return l1;
        }
        else{
            l2->next = merge(l2->next, l1);
            return l2;
        }
    }
    ListNode* findMiddleOfLL(ListNode* head){
        ListNode* slow = head, *fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* mid = findMiddleOfLL(head);
        ListNode* left = head;
        ListNode* right = mid->next;
        mid->next = NULL;
        
        ListNode* leftSorted = sortList(left);
        ListNode* rightSorted = sortList(right);

        return merge(leftSorted, rightSorted);
    }
};
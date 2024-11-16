/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return NULL; 
        Node* curr = head;
        Node* next;
        while(curr!=NULL){
            next = curr->next;
            curr->next = new Node(curr->val);
            curr->next->next=next;
            curr = next;
        }
        curr = head;
        while(curr!=NULL && curr->next!=NULL){
            if(curr->random!=NULL){
                curr->next->random = curr->random->next;
                curr=curr->next->next;
            }
            else {
                curr->next->random = NULL;
                curr=curr->next->next;
            }
        }
        Node* original = head;
        Node* copy = head->next;

        Node* temp = copy;

        while(original && copy){
            if(original->next!=NULL){
                original->next= original->next->next;
            }
            if(copy->next!=NULL){
                copy->next= copy->next->next;
            }
            original = original->next;
            copy = copy->next;
        }
        return temp;

    }
};
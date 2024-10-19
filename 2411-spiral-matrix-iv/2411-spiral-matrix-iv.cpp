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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        ListNode* curr = head;
        bool isEmpty = false;
        if(curr!=NULL){
        isEmpty = false;
        }
        else isEmpty = true;

        vector<vector<int>> v(m, vector<int> (n));

        int top =0;
        int right=n-1;
        int down=m-1;
        int left=0;

        while(top<=down && left<=right){
            for(int i =left;i<=right;i++){
                if(curr==NULL){
                    v[top][i] = -1;
                    continue;
                }
                else {
                    v[top][i] = curr->val;
                    curr=curr->next;
                }
            }
            top++;

            for(int i = top;i<=down;i++){
                if(curr==NULL){
                    v[i][right] = -1;
                    continue;
                }
                else{
                    v[i][right] = curr->val;
                    curr=curr->next;
                }
            }
            right--;
            if(top<=down){
                for(int i = right;i>=left;i--){
                    if(curr==NULL){
                        v[down][i] = -1;
                        continue;
                    }
                    else{
                        v[down][i] =  curr->val;
                        curr=curr->next;
                    }
                }
            down--;
            }
            if(left<=right){
                for(int i = down;i>=top;i--){
                    if(curr==NULL){
                        v[i][left] = -1;
                        continue;
                    }
                    else{
                        v[i][left] = curr->val;
                        curr=curr->next;
                    }
                }
            }
            left++;
        }


        return v;



    }
};
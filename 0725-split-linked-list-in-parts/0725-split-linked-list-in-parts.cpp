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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans;
        ListNode* tmp = head;
        int size = 0;
        while(tmp)
        {
            tmp = tmp->next;
            size++;
        }
        int excess = size%k;
        int count = size/k;
        while(head)
        {
            ListNode* tmp = head;
            if(excess)
            {
                for(int i=1; i<count+1; i++)
                {
                    head = head->next;
                }
                ListNode* nxthead = head->next;
                head->next = nullptr;
                ans.push_back(tmp);
                head = nxthead;
                excess--;
            }
            else
            {
                for(int i=1; i<count; i++)
                {
                    head = head->next;
                }
                ListNode* nxthead = head->next;
                head->next = nullptr;
                ans.push_back(tmp);
                head = nxthead; 
            }
        }
        if(k>size)
        {
            int diff = k - size;
            while(diff)
            {
                ans.push_back(nullptr);
                diff--;
            }
        }
        return ans;
    }
};
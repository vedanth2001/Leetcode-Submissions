/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> zigZagResult;
        if(root == NULL) return zigZagResult;
        queue<TreeNode*> q;
        stack<TreeNode*> st;
        q.push(root);
        bool reverse = false;
        while(!q.empty()){
            int count = q.size();
            vector<int> zigZagLevel;
            for(int i =0;i<count;i++){
                TreeNode* curr = q.front();
                q.pop();
                if(reverse){
                    st.push(curr);
                }
                else{
                    zigZagLevel.push_back(curr->val);
                }
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            if(reverse){
                while(!st.empty()){
                    TreeNode* curr = st.top();
                    st.pop();
                    zigZagLevel.push_back(curr->val);
                }
            }
            reverse = !reverse;
            zigZagResult.push_back(zigZagLevel);

        }
        return zigZagResult;
    }
};
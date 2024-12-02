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
    TreeNode* constructTree(vector<int>& inorder, vector<int>& postorder, int start, int end, int &pre){
        if(start>end) return NULL;
        TreeNode* root = new TreeNode(postorder[pre--]);
        int index;
        for(int i =start; i <= end;i++){
            if(inorder[i] == root->val){
                index = i;
                break;
            }
        }

        root->right = constructTree(inorder, postorder, index + 1, end, pre);
        root->left = constructTree(inorder, postorder, start, index - 1, pre);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int start = 0;
        int end = inorder.size() - 1;
        return constructTree(inorder, postorder, start, end, end);

    }
};
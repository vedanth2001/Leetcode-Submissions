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
    int pre = 0;
    TreeNode* constructTree(vector<int>& preorder, vector<int>& inorder, int start, int end){
        if(start > end) return NULL;
        TreeNode* root = new TreeNode(preorder[pre++]);
        int index;
        for(int i =start;i<=end;i++){
            if(root->val == inorder[i]){
                index = i;
                break;
            }
        }
        root->left = constructTree(preorder, inorder, start, index - 1);
        root->right = constructTree(preorder, inorder, index + 1, end);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int start = 0;
        int end = preorder.size() - 1;
        TreeNode* curr = constructTree(preorder, inorder, start, end);
        return curr;
    }
};
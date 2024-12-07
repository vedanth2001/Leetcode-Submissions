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
    void inorder(TreeNode* root, int k, int &count, int &res){
        if(root == NULL) return;
        inorder(root->left, k, count, res);
        if(count++ == k){
            res = root->val;
            return;
        }
        inorder(root->right, k, count, res);
    }
    int kthSmallest(TreeNode* root, int k) {
        int count = 1;
        int res = 0;
        inorder(root, k, count, res);
        return res;
    }
};
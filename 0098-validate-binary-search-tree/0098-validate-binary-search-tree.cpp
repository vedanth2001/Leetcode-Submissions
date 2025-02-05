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
    bool isValid(TreeNode* root, long long minVal, long long maxVal){
        if(root==NULL) return true;
        if(root->val >= maxVal || root->val <=minVal) return false;
        return isValid(root->left, minVal, root->val) && 
        isValid(root->right, root->val, maxVal);
    }
    bool isValidBST(TreeNode* root) {
        if(root == NULL) return true;
        // if(root->left!=NULL && root->left->val > root->val) return false;
        // if(root->right!=NULL && root->right->val < root->val) return false;

        return isValid(root, LLONG_MIN, LLONG_MAX);
    }
};
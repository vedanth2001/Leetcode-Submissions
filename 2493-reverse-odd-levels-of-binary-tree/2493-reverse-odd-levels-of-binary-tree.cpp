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
    void reverseLevels(TreeNode* left, TreeNode* right, int level){
        if (left == NULL || right == NULL) {
            return;
        }
        if(level % 2 != 0){
            swap(left->val, right->val);
        }
        reverseLevels(left->left, right->right, level + 1);
        reverseLevels(left->right, right->left, level + 1);
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        if(root == NULL) return NULL;
        int level =1;
        reverseLevels(root->left, root->right, level);
        return root;
    }
};
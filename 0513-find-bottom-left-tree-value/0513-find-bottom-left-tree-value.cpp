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
    int maxLevel = 0;
    void leftView(TreeNode* root, int level, vector<int> &left){
        if(root==NULL) return ;
        if(maxLevel < level) {
            left.push_back(root->val);
            maxLevel = level;
        }
        leftView(root->left, level+1, left);
        leftView(root->right, level+1, left);
    }
    int findBottomLeftValue(TreeNode* root) {
        vector<int> x;
        leftView(root, 1, x);
        return x[x.size()-1];
    }
};
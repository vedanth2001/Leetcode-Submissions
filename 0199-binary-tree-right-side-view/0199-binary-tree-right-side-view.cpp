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
    void rightSide(TreeNode* root, int level, int &maxLevel, vector<int> &rightView){
        if(root==NULL) return;
        if(maxLevel < level){
            rightView.push_back(root->val);
            maxLevel = level;
        }
        rightSide(root->right, level+1, maxLevel, rightView);
        rightSide(root->left, level+1, maxLevel, rightView);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> rightView;
        int maxLevel = 0;
        if(root==NULL) return rightView;
        rightSide(root, 1, maxLevel, rightView);
        return rightView;
    }
};
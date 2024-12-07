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
    TreeNode* tree(vector<int>& nums, int start, int end){
        if(start>end) return NULL;
        int maxI = start;
        for(int i = start;i<=end;i++){
            if(nums[i] > nums[maxI]){
                maxI = i;
            }
        }
        TreeNode* root = new TreeNode(nums[maxI]);
        root->left = tree(nums, start, maxI - 1);
        root->right = tree(nums, maxI + 1, end);
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int start = 0;
        int end = nums.size() - 1;
        TreeNode* root = tree(nums, start, end);
        return root;
    }
};
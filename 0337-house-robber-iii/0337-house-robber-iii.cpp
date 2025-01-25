

class Solution {
public:
    unordered_map<TreeNode*, unordered_map<bool, int>> dp;

    int robHelper(TreeNode* root, bool canTake) {
        if (root == NULL) return 0;
        if (dp[root].count(canTake)) return dp[root][canTake];

        if (canTake) {
            return dp[root][canTake] = max(
                root->val + robHelper(root->left, 0) + robHelper(root->right, 0),
                robHelper(root->left, 1) + robHelper(root->right, 1)
            );
        }
        return dp[root][canTake] = robHelper(root->left, 1) + robHelper(root->right, 1);
    }

    int rob(TreeNode* root) {
        return robHelper(root, 1);
    }
};

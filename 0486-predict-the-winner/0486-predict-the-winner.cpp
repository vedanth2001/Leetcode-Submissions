class Solution {
public:
     int helper(vector<int>& nums, int left, int right, vector<vector<int>>& memo) {
        // Base case: only one element left
        if (left == right) {
            return nums[left];
        }

        // If this subproblem has already been solved, return the stored result
        if (memo[left][right] != -1) {
            return memo[left][right];
        }

        // Current player picks either left or right
        int pickLeft = nums[left] - helper(nums, left + 1, right, memo);
        int pickRight = nums[right] - helper(nums, left, right - 1, memo);

        // Store the result in the memoization table
        memo[left][right] = max(pickLeft, pickRight);
        return memo[left][right];
    }

    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();

        // Initialize memoization table with -1 (indicating uncomputed values)
        vector<vector<int>> memo(n, vector<int>(n, -1));

        // Get the score difference for the entire array (from index 0 to n-1)
        int result = helper(nums, 0, n - 1, memo);

        // If Player 1's score difference is >= 0, they can win
        return result >= 0;
    }
};
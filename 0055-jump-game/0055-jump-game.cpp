class Solution {
public:
    bool canJumpHelper(vector<int>& nums, int n, vector<int>& mem) {
        if (n == 1) return true;  // If we're at the first index, we can reach it
        if (mem[n - 1] != -1) return mem[n - 1];  // Return cached result

        for (int i = 0; i < n - 1; i++) {
            if (nums[i] + i >= n - 1) {  // Can we reach the last index from index i?
                if (canJumpHelper(nums, i + 1, mem)) {
                    return mem[n - 1] = true;  // Cache the result
                }
            }
        }
        return mem[n - 1] = false;  // Cache the result if not reachable
    }

    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> mem(n, -1);  // Initialize memoization array
        return canJumpHelper(nums, n, mem);
    }
};

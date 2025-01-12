class Solution {
public:
    int findBitonicLength(vector<int>& nums, int n) {
        vector<int> lis(n, 1);  // Longest Increasing Subsequence
        vector<int> lds(n, 1);  // Longest Decreasing Subsequence
        int bitonicLength = 0;

        // Compute LIS for each index
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    lis[i] = max(lis[i], lis[j] + 1);
                }
            }
        }

        // Compute LDS for each index
        for (int i = n - 2; i >= 0; i--) {
            for (int j = n - 1; j > i; j--) {
                if (nums[i] > nums[j]) {
                    lds[i] = max(lds[i], lds[j] + 1);
                }
            }
        }

        // Find the maximum bitonic length
        for (int i = 1; i < n - 1; i++) {  // Ensure the peak is not at the boundaries
            if (lis[i] > 1 && lds[i] > 1) {  // Valid bitonic subsequence
                bitonicLength = max(bitonicLength, lis[i] + lds[i] - 1);
            }
        }

        return bitonicLength;
    }

    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        int length = findBitonicLength(nums, n);
        return n - length;
    }
};
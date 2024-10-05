class Solution {
public:
    int isPair(vector<int>& nums, int &sumClosest, int &minDiff, int target, int ind) {
        int start = ind + 1;
        int n = nums.size();
        int end = n - 1;
        
        while (start < end) {
            int sum = nums[ind] + nums[start] + nums[end];  // Calculate the sum of the triplet

            if (abs(sum - target) < minDiff) {
                minDiff = abs(sum - target);  // Update the minimum difference
                sumClosest = sum;             // Update the closest sum
            }

            if (sum == target) {
                return sum;  // If exactly equal to target, return immediately
            } else if (sum > target) {
                end--;  // Move the end pointer to reduce the sum
            } else {
                start++;  // Move the start pointer to increase the sum
            }
        }
        return sumClosest;  // Return the closest sum
    }

    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());  // Sort the array for two-pointer technique
        int sumClosest = 0;              // Store the closest sum
        int minDiff = INT_MAX;           // Initialize the minimum difference
        int n = nums.size();

        for (int i = 0; i < n - 2; i++) {
            sumClosest = isPair(nums, sumClosest, minDiff, target, i);
        }

        return sumClosest;
    }
};

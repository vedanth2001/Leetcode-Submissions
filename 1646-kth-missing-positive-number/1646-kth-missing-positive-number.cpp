class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int low = 0;
        int high = n - 1;
        
        // Perform binary search to find the correct index
        while (low <= high) {
            int mid = low + (high - low) / 2;
            // Number of missing numbers before arr[mid]
            int missing = arr[mid] - (mid + 1);
            
            if (arr[mid] - (mid + 1) < k) {
                // We need more missing numbers, so move to the right
                low = mid + 1;
            } else {
                // We have enough missing numbers, so move to the left
                high = mid - 1;
            }
        }
        
        // After binary search, `low` is the first index where the missing numbers are enough
        // `low + k` gives the k-th missing number after all processed elements in the array
        return low + k;
    }
};

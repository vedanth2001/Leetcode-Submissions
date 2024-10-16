class Solution {
public:
    // Modified merge function to count smaller elements
    void merge(vector<int> &nums, vector<int> &indices, int low, int mid, int high, vector<int> &count) {
        int n1 = mid - low + 1;
        int n2 = high - mid;

        vector<int> leftIndices(n1);
        vector<int> rightIndices(n2);

        // Copy the indices of the left and right subarrays
        for (int i = 0; i < n1; i++) {
            leftIndices[i] = indices[low + i];
        }
        for (int i = 0; i < n2; i++) {
            rightIndices[i] = indices[mid + 1 + i];
        }

        int i = 0, j = 0, k = low;
        int rightCount = 0;  // Track how many elements from the right are smaller

        // Merge the two halves while counting smaller elements
        while (i < n1 && j < n2) {
            if (nums[rightIndices[j]] < nums[leftIndices[i]]) {
                indices[k++] = rightIndices[j++];
                rightCount++;  // This right element is smaller than the current left
            } else {
                count[leftIndices[i]] += rightCount;  // Add rightCount to the left element
                indices[k++] = leftIndices[i++];
            }
        }

        // Process remaining elements in the left half
        while (i < n1) {
            count[leftIndices[i]] += rightCount;  // Add the remaining smaller elements from the right
            indices[k++] = leftIndices[i++];
        }

        // Process remaining elements in the right half
        while (j < n2) {
            indices[k++] = rightIndices[j++];
        }
    }

    // Modified merge sort to operate on the indices array
    void mergeSort(vector<int>& nums, vector<int>& indices, int low, int high, vector<int>& count) {
        if (low >= high) return;

        int mid = low + (high - low) / 2;
        mergeSort(nums, indices, low, mid, count);
        mergeSort(nums, indices, mid + 1, high, count);
        merge(nums, indices, low, mid, high, count);
    }

    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> count(n, 0);
        vector<int> indices(n);

        // Initialize the indices array to store original indices
        for (int i = 0; i < n; ++i) {
            indices[i] = i;
        }

        // Perform merge sort and count smaller elements
        mergeSort(nums, indices, 0, n - 1, count);
        return count;
    }
};

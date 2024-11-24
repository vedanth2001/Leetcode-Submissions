class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // Step 1: Find the next greater element for all nums2 elements
        stack<int> nextGreater;
        unordered_map<int, int> nextGreaterMap;
        int n = nums2.size();

        for (int i = n - 1; i >= 0; i--) {
            while (!nextGreater.empty() && nextGreater.top() <= nums2[i]) {
                nextGreater.pop();
            }
            nextGreaterMap[nums2[i]] = nextGreater.empty() ? -1 : nextGreater.top();
            nextGreater.push(nums2[i]);
        }

        // Step 2: Fetch results for nums1
        vector<int> result;
        for (int num : nums1) {
            result.push_back(nextGreaterMap[num]);
        }

        return result;
    }
};

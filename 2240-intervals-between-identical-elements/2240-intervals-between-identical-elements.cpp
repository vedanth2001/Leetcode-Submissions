class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
        
        int n = arr.size();
        vector<long long> result(n, 0);
        unordered_map<int, vector<int>> mp;
        
        // Step 1: Build the map with all indices of each unique number
        for (int i = 0; i < n; i++) {
            mp[arr[i]].push_back(i);
        }

        // Step 2: Calculate the distances for each unique number
        for (auto& [num, list] : mp) {
            long long totalSum = 0;
            long long preSum = 0;
            int m = list.size();
            
            // Calculate the total sum of all indices for the current number
            for (int idx : list) {
                totalSum += idx;
            }

            // Traverse through the list of indices
            for (int i = 0; i < m; i++) {
                long long currIdx = list[i];

                // Prefix part: sum of distances to all previous indices
                long long prefixPart = (long long)(i * currIdx) - preSum;
                
                // Suffix part: sum of distances to all following indices
                long long suffixPart = (totalSum - preSum) - (long long)(m - i) * currIdx;

                // Store the result for the current index
                result[currIdx] = prefixPart + suffixPart;

                // Update prefix sum
                preSum += currIdx;
            }
        }

        return result;
    }
};

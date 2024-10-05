class Solution {
public:
    int countQuadruplets(std::vector<int>& nums) {
        int res = 0, n = nums.size();
        unordered_map<int, int> freq;
        
        freq[nums[n-1]]++;
        
        for (int i = n-2; i >= 0; i--) {
            for (int j = i-1; j >= 0; j--)
                for (int k = j-1; k >= 0; k--) 
                    res += freq[nums[i]+nums[j]+nums[k]];
            freq[nums[i]]++;
        }
		
        return res;
    }
};
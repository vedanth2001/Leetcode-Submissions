class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if (n < k) return 0;
        unordered_map<int, int> mp;
        long long sum = 0;

        for(int i=0;i<k;i++){
            mp[nums[i]]++;
            sum+=nums[i];
        }

        long long maxSum = (mp.size() == k) ? sum : 0;
        
        for(int i=k;i<n;i++){
            mp[nums[i-k]]--;
            if(mp[nums[i-k]]==0){
                mp.erase(nums[i-k]);
            }
            mp[nums[i]]++;
            sum-=nums[i-k];
            sum+=nums[i];
            if(mp.size()==k){
                maxSum=max(sum, maxSum);
            }
        }
        return maxSum;
    }
};
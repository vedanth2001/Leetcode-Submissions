class Solution {
public:
    bool partitionHelper(vector<int>& nums, int i, int sum, vector<int> &mem){
        if(i<0 || sum<0) return false;
        if(sum==0) return true;
        if(mem[sum]!=-1) return mem[sum];
        if(partitionHelper(nums, i-1, sum, mem) || partitionHelper(nums, i-1, sum-nums[i], mem)) return mem[sum]=true;
        return mem[sum]=false;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i =0;i<n;i++){
            sum+=nums[i];
        }
        vector<bool> dp(sum+1, 0);
        dp[0] = 1;
        if(sum%2!=0) return false;
        int target = sum/2;
         for (int num : nums) {
            for (int j = target; j >= num; j--) {
                dp[j] = dp[j] || dp[j - num];
            }
        }
        return dp[target];
    }
};
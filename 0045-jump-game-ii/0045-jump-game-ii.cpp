class Solution {
public:
    int jumpHelper(vector<int>& nums, int n, vector<int> &mem){
        if(n==1) return 0;
        int res = INT_MAX;
        if(mem[n]!=-1) return mem[n];
        for(int i =0;i<n-1;i++){
            if(nums[i]+i>=n-1){
            int sub_res = jumpHelper(nums, i+1, mem);
            res = min(res, sub_res+1);
            mem[n] = res;
            }
        }
        return mem[n];
    }
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;
        for(int i = 1;i<n;i++){
            for(int j =0;j<i;j++){
                if(nums[j]+j>=i){
                    dp[i] = min(dp[j]+1, dp[i]);
                }
            }
        }
        return dp[n-1];
    }
};
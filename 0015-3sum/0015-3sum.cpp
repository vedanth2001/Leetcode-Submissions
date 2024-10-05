class Solution {
public:
    void isPair(vector<int>& nums, int ind, int target, vector<vector<int>>& res){
        int n=nums.size();
        int start=ind+1;
        int end=n-1;
        while(start<end){
            vector<int> curr;
            if(nums[start]+nums[end]==target){
                
                curr.push_back(nums[ind]);
                curr.push_back(nums[start]);
                curr.push_back(nums[end]);
                res.push_back(curr);
               while (start < end && nums[start] == nums[start + 1]) start++;
                while (start < end && nums[end] == nums[end - 1]) end--;
                start++;
                end--;
            }
            else if(nums[start]+nums[end]>target){
                end--;
            }
            else start++;
        }
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n= nums.size();
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for(int i=0;i<n-2;i++){
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            isPair(nums,i,0-nums[i],res);
        }
        return res;
    }
};
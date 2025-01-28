class Solution {
public:
 void help(vector<int>&nums,set<vector<int>>&s,int idx){
        if(idx==nums.size()){
            s.insert(nums);
            return;
        }
        for(int i=idx;i<nums.size();i++){
            swap(nums[i],nums[idx]);
            help(nums,s,idx+1);
            swap(nums[i],nums[idx]);    
            }
 }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>>s;
        help(nums,s,0);
         vector<vector<int>>res;
        for(vector<int> x:s){
            res.push_back(x);
        }
       return res;
    }
};
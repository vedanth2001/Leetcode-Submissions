class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int count = 0;
        unordered_map<int, int> mp;
        int n = nums.size();
        int pre =0;
        for(int i =0;i<n;i++){
            pre+=nums[i];
            if(pre==goal){
            count++;
            }
            if(mp.find(pre-goal)!=mp.end())
            {
                count+=mp[pre-goal];
            }
            mp[pre]++;
        }
        return count;
    }
};
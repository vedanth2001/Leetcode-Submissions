class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        mp[0]=-1;
        int pre=0;
        for(int i =0;i<n;i++){
            pre+=nums[i];
            if(k!=0){
                pre%=k;
            }
            if(mp.find(pre)!=mp.end()){
                if(i-mp[pre] >=2)
                return true;
            }
            else{
                mp[pre] = i;
            }
        }
        return false;
    }
};
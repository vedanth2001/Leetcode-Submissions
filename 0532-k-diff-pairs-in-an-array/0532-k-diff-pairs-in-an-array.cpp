class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int n = nums.size();
        for(int i =0;i<n;i++){
            mp[nums[i]]++;
        }
        int count = 0;
        for(auto pair:mp){
            if(k==0){
                if(pair.second>1)
                count++;
            }
            else if(k>0){
                if(mp.count(pair.first+k))
                count++;
            }
        }
        return count;
    }
};
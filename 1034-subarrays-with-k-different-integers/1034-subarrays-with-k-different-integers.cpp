class Solution {
public:
    int atMostKDistinct(vector<int>& nums, int k){
        int n = nums.size();
        unordered_map<int, int> mp;
        int l = 0;
        int r = 0;
        int count = 0;
        while(r<n){
            mp[nums[r]]++;
            while(mp.size()>k){
                mp[nums[l]]--;
                if(mp[nums[l]]==0) mp.erase(nums[l]);
                l++;
            }
            count+=r-l+1;
            r++;
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int subArrays = atMostKDistinct(nums, k) - atMostKDistinct(nums, k-1);
        return subArrays;
    }
};
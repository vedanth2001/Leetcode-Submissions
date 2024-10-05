class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int count=0;
        unordered_map<int, int> mp;
        for(auto a:nums1){
            for(auto b:nums2){
                mp[a+b]++;
            }
        }
        for(auto c: nums3){
            for(auto d: nums4){
                auto it=mp.find(-c-d);
                if(it!=mp.end())
                count+=it->second;
            }
        }
        return count;
    }
};
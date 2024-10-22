class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        // sort(nums.begin() , nums.end());
        unordered_map<int , int> m;
        for(int j=0; j<nums.size(); j++){
            m[nums[j]]++;
        }
        int count = 0;
        for(int i=0; i<nums.size(); i++){
            int val = nums[i] + k;
            if(m.count(val)){
             count+=m[val];
            };
   
        };

        return count;
    }
};
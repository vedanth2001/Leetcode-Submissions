class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        int n = nums.size();
        int i =0;
        int j =n-1;
        sort(nums.begin(), nums.end());
        int res=0;
        while(i<j){
            if(nums[i]+nums[j]<target){
                res+=(j-i);
                i++;
            }
            else {
                j--;
            }
        }
        return res;
    }
};
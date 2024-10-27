class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int res = INT_MAX;
        int n = nums.size();
        int startI = 0;
        int subarraySum = 0;
        for(int endI=0;endI<n;endI++){
            subarraySum+=nums[endI];

            while(subarraySum>=target){
                res = min(res, endI-startI+1);
                subarraySum -= nums[startI];
                startI ++;
            }

        }
        if(res == INT_MAX){
            return 0;
        }
        return res;
    }
};
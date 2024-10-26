class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long count = 0;
        int i =0;
        int n = nums.size();
        long long sum = 0;
        for(int j =0;j<n;j++){
            sum += nums[j];
            while(k<=(sum*(j-i+1))){
                sum -= nums[i];
                i++;
            }
            count+=(j-i+1);
        }
        return count;
    }
};
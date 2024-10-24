class Solution {
public:
    int findUpper(vector<int>& nums, int low, int high, int target){
        while(low<=high){
            int mid = low+(high-low)/2;
            if(nums[mid]>target){
                high=mid-1;
            }
            else {
                low=mid+1;
            }
        }
        return high;
    }
    int findLower(vector<int>& nums, int low, int high, int target){
        while(low<=high){
            int mid = low+(high-low)/2;
            if(nums[mid]<target){
                low=mid+1;
            }
            else
            high = mid-1;
        }
        return low;
    }
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long result = 0;
        int n =nums.size();
        sort(nums.begin(), nums.end());
        for(int i =0;i<n-1;i++){
            int high = upper - nums[i];
            int low = lower - nums[i];

            int maxI = findUpper(nums, i+1, n-1, high);
            int minI = findLower(nums, i+1, n-1, low);

            if(minI<=maxI){
                result += (maxI - minI +1) ; 
            }
        }
        return result;

    }
};
class Solution {
public:
    int ceilHelper(vector<int> &tail, int low, int high, int num){
        while(low<high){
            int mid = low+(high-low)/2;
            if(tail[mid] >= num){
                high = mid;
            }
            else low = mid+1;
        }
        return low;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int len = 1;
        vector<int> tail;
        tail.push_back(nums[0]);
        for(int i =1;i<n;i++){
            if(nums[i]>tail[len-1]){
                tail.push_back(nums[i]);
                len++;
            }
            else{
                int ceilIndex = ceilHelper(tail, 0, len-1, nums[i]);
                tail[ceilIndex] = nums[i];
            }
        }
        return len;
    }
};
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
       int n = nums.size();
       sort(nums.begin(), nums.end());
       vector<int> ans(n);
        int mid = (n-1)/2;
        int high = n-1;
        for(int i=0; i<n; i++){
            if(i%2==1){
                ans[i] = nums[high--];
                
            }
            else {
                ans[i] = nums[mid--];
               
            }
        }
        nums = ans;
    }
};
class Solution {
public:
    int partition(vector<int>& nums, int low, int high){
        int win=low-1;
        int pivot=nums[high];
        for(int i=low;i<high;i++){
            if(nums[i]<pivot){
                win++;
                swap(nums[win], nums[i]);
            }
            
        }
        swap(nums[win+1],nums[high]);
        return win+1;;

    }
    int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size();
        int l=0;
        int r=n-1;
        while(l<=r){
        int p= partition(nums, l, r);
        if(p==(n-k)){
            return nums[p];
        }
        else if(p>(n-k)){
            r=p-1;
    }
        else l=p+1;
    }
        return -1;
    }
};
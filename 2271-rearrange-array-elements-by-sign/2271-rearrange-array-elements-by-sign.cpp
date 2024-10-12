class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        int P=0;
        int N=1;
        vector<int> res(n);
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                res[P]=nums[i];
                P=P+2;
            }
            else if(nums[i]<0){
                res[N]=nums[i];
                N=N+2;
            }
        }
        return res;
    }
};
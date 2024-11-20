class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int count = 1;
        int majElement = nums[0];
        for(int i =1;i<n;i++){
            if(nums[i] == majElement){
                count++;
            }
            else{
                count--;
                if(count==0){
                    count=1;
                    majElement = nums[i];
                }
            }
        }
        return majElement;

    }
};
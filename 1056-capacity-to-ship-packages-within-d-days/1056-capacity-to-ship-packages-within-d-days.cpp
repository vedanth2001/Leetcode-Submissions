class Solution {
public:
    bool feasible(vector<int>& weights, int days, int capacity){
        int curr=0;
        int day=1;
        for(auto weight:weights){
            if(curr+weight>capacity){
                day++;
                curr=weight;
            }
            else{
                curr+=weight;
            }
        }
        return day<=days;

    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        int sum=0;
        int low=0;
        for(int i=0;i<n;i++){
            sum+=weights[i];
            low=max(weights[i],low);
        }
      
        int high=sum;
        int res=high;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(feasible(weights, days, mid)){
                res=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return res;
    }
};
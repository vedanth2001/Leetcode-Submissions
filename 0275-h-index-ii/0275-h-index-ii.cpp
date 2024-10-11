class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n=citations.size();
        int low=0;
        int high=n-1;
        int maxI=0;
        while(low<=high){
            int mid= low+(high-low)/2;
            if(citations[mid]>=n-mid){
                maxI=max(maxI, n-mid);
                high=mid-1;
            }
            else {
                low=mid+1;
            }
            
        }
        return maxI;
    }
};
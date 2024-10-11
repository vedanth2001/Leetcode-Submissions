class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n= citations.size();
        sort(citations.begin(),citations.end());
        int maxI=0;
        for(int i=0;i<n;i++){
            if(citations[i]>=n-i){
                maxI=max(maxI, n-i);
            }
        }
        return maxI;

    }
};
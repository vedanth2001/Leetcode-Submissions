class Solution {
public:
    static bool myComp(vector<int> &a, vector<int> &b){
       return a[1] < b[1];
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), myComp);
        int res = 1;
        int n = pairs.size();
        int currMax = pairs[0][1];
        for(int i=1;i<n;i++){
            if(currMax<pairs[i][0]){
                res++;
                currMax = pairs[i][1];
            }
        }
        return res;
    }
};
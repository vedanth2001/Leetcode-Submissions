class Solution {
public:
    static bool myComp(vector<int> &a, vector<int> &b){
        return a[0] < b[0];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int res= 0;
        int count= 0;
        sort(intervals.begin(), intervals.end(), myComp);
        for(int i=1;i<n;i++){
            if(intervals[res][1] > intervals[i][0]){
                count++;
                if(intervals[res][1]>intervals[i][1]){
                    res=i;
                }
            }
            else{
               res=i;
            }
        }
        return count;
    }
};
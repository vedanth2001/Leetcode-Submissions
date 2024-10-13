class Solution {
public:
    static bool myComp(const vector<int> &a, const vector<int> &b){
        return a[0] < b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), myComp);
        int res = 0;
        for(int i = 1 ; i < n; i++){
            if(intervals[res][1] >= intervals[i][0]){
                intervals[res][1] = max(intervals[res][1], intervals[i][1]);
            }
            else{
                res++;
                intervals[res] = intervals[i];
            }
        }
        intervals.resize(res + 1);
        return intervals;


    }
};
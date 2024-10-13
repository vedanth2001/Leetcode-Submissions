class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        int i=0;
        while(i<n && intervals[i][0] < newInterval[0]){
            i++;
        } 
        intervals.insert(intervals.begin()+i, newInterval);
        n++;
        int res=0;
        for(int j=1;j<n;j++){
            if(intervals[res][1]>=intervals[j][0]){
                intervals[res][1] = max(intervals[res][1], intervals[j][1]); 
            }
            else{
                res++;
                intervals[res] = intervals[j];
            }
        }
        intervals.resize(res + 1);
        return intervals;

    }
};


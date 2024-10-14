class Solution {
public:
    static bool myComp(vector<int> &a, vector<int> &b){
        return a[0]<b[0];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        int res= 0;
        sort(points.begin(), points.end(), myComp);

        for(int i=1;i<n;i++){
            if(points[res][1] >= points[i][0]){
                points[res][0] = max(points[res][0], points[i][0]);
                points[res][1] = min(points[res][1], points[i][1]);
            }
            else{
                res++;
                points[res]=points[i];
            }
        }
        
        return res+1;


    }
};
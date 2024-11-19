class Solution {
public:
    static bool myComp(const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    }
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        int n = points.size();
        sort(points.begin(), points.end(), myComp);
        int res = INT_MIN;
        for(int i =0;i<n-1;i++){
            if(points[i+1][0]-points[i][0] > res){
                res = points[i+1][0]-points[i][0];
            }
        }
        return res;
    }
};
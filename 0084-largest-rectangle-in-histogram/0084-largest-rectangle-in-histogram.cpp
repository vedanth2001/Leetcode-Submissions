class Solution {
public:
    vector<int> findPreviousSmaller(vector<int>& heights){
        vector<int> ps;
        stack<int> s;
        int n = heights.size();
        for(int i =0;i<n;i++){
            while(!s.empty() && heights[s.top()]>=heights[i]){
                s.pop();
            }
            if(s.empty()){
                ps.push_back(-1);
            }
            else{
                ps.push_back(s.top());
            }
            s.push(i);
        }
        return ps;
    }
    vector<int> findNextSmaller(vector<int>& heights){
        int n = heights.size();
        vector<int> ns;
        stack<int> s;
        for(int i =n-1;i>=0;i--){
            while(!s.empty() && heights[s.top()]>=heights[i])
            s.pop();

            if(s.empty()) ns.push_back(n);
            else ns.push_back(s.top());

            s.push(i);
        }
        reverse(ns.begin(), ns.end());
        return ns;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int res = 0;
        vector<int> ps = findPreviousSmaller(heights);
        vector<int> ns = findNextSmaller(heights);
        for(int i =0;i<n;i++){
            int width = ns[i] - ps[i] - 1;
            int curr = heights[i] * width;
            res = max(res, curr);
        }
        return res;
    }
};
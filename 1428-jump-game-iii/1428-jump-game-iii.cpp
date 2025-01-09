class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        queue<int> q;
        int n = arr.size();
        q.push(start);
        vector<int> visited(n, 0);
        while(!q.empty()){
            int i = q.front();
            q.pop();
            visited[i] = 1;
            if(arr[i] == 0) return true;
            if(i-arr[i]>=0 && visited[i-arr[i]]==0) q.push(i-arr[i]);
            if(i+arr[i]<n  && visited[i+arr[i]]==0)  q.push(i+arr[i]);
        }
        return false;
    }
};
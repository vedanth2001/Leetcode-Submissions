class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> result;
        queue<int>q;
        for(auto &v: prerequisites){
            adj[v[1]].push_back(v[0]);
        }
        vector<int> inDeg(numCourses);
        for(int i =0;i<numCourses;i++){
            for(int &v:adj[i]){
                inDeg[v]++;
            }
        }
        for(int i =0;i<numCourses; i++){
            if(inDeg[i]==0)
            q.push(i);
        }
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            result.push_back(curr);
            for(int &v:adj[curr]){
                inDeg[v]--;
                if(inDeg[v]==0)q.push(v);
            }
        }
        if (result.size() != numCourses) {
            return {}; 
        }
        return result;
    }
};
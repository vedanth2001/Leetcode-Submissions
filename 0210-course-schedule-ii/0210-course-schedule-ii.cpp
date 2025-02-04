class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> courseOrder;
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses);
        for(auto nodes: prerequisites){
            adj[nodes[1]].push_back(nodes[0]);
            indegree[nodes[0]]++;
        }
        queue<int> q;
        for(int i =0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            courseOrder.push_back(node);
            for(auto neighbour: adj[node]){
                indegree[neighbour]--;
                if(indegree[neighbour]==0){
                    q.push(neighbour);
                }
            }
        }
        if(courseOrder.size() != numCourses) return {}; 
        return courseOrder;
    }
};
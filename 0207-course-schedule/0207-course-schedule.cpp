class Solution {
public:
    bool checkDfs(int node, vector<vector<int>> &adj, vector<int> &vis, vector<int> &recSt){
        vis[node]=1;
        recSt[node]=1;
        for(auto v:adj[node]){
            if(vis[v]==0){
                if(checkDfs(v, adj, vis, recSt)) return true;
            }
            else if(recSt[v]==1) return true;
        }
        recSt[node] = 0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);  // Create an adjacency list
        for (auto& edge : prerequisites) {
            adj[edge[1]].push_back(edge[0]);  // Build the graph
        }

        vector<int> vis(numCourses, 0);
        vector<int> recSt(numCourses, 0);
        for(int i =0;i<numCourses;i++){
            if(vis[i]==0){
                if(checkDfs(i, adj, vis, recSt)) return false;
            }
        }
        return true;
    }
};
class Solution {
public:
    void findBFS(vector<vector<int>> &adj, int i, vector<bool> &vis, vector<int> &nodes){
        queue<int> q;
        q.push(i);
        vis[i] = true;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            nodes.push_back(curr);
            for(int edge: adj[curr]){
                if(vis[edge] == false){
                    q.push(edge);
                    vis[edge] = true;
                }
            }
        }
        return;
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<bool> vis(n, 0);
        int count = 0;
        for(auto edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        for(int i =0;i<n;i++){
            if(vis[i] == 0){
                vector<int> nodes;
                findBFS(adj, i, vis, nodes);
                int nodeCount = nodes.size();
                int edgeCount = 0;

                for (int node : nodes) {
                    edgeCount += adj[node].size();
                }
                edgeCount /= 2;
                if (edgeCount == (nodeCount * (nodeCount - 1)) / 2) {
                    count++;
                }

            }
        }
        return count;
    }
};
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n+1);
        int minTime = 0;
        for (auto edge : times) {
            int u = edge[0], v = edge[1], w = edge[2];
            adj[u].push_back({v, w});
        }
         vector<int> dist(n+1, INT_MAX);
        dist[k] = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, k});
        while(!pq.empty()){
            int node = pq.top().second;
            int currDist = pq.top().first;
            pq.pop();
            // calculates distance from current node to this node.
            for(auto [neighbour, weight] : adj[node]){
                if(dist[neighbour] > currDist+weight){
                    dist[neighbour] = currDist+weight;
                    pq.push({dist[neighbour], neighbour});
                }
            }
        }
        for (int i = 1; i <= n; i++) {  
            if (dist[i] == INT_MAX) return -1;  
            minTime = max(minTime, dist[i]);
        }
        return minTime;
    }
};
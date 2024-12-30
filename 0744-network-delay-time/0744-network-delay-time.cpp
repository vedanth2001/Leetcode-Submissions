class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Adjacency list to store the graph
        vector<vector<pair<int, int>>> adj(n + 1);  // n + 1 for 1-based indexing
        for (auto& time : times) {
            int u = time[0], v = time[1], w = time[2];
            adj[u].emplace_back(v, w);
        }

        // Distance vector initialized to INT_MAX, for each node
        vector<int> dist(n + 1, INT_MAX);  // n + 1 for 1-based indexing
        dist[k] = 0;

        // Min-heap priority queue to store {distance, node}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});  // Start from node `k` with distance 0

        while (!pq.empty()) {
            auto [currentDist, node] = pq.top();
            pq.pop();

            // Skip processing if the current distance is outdated
            if (currentDist > dist[node]) continue;

            // Relaxation step for adjacent nodes
            for (auto& [neighbor, weight] : adj[node]) {
                if (dist[node] + weight < dist[neighbor]) {
                    dist[neighbor] = dist[node] + weight;
                    pq.push({dist[neighbor], neighbor});
                }
            }
        }

       
        int res = 0;  
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX) return -1;  // If any node is unreachable
            res = max(res, dist[i]);
        }

        return res;
    }
};

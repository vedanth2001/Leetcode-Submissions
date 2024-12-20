class Solution {
public:
    bool checkBfs(int source, vector<int> &colour, vector<vector<int>>& graph){
        queue<int> q;
        q.push(source);
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            for(int &adj:graph[curr]){
                if(colour[adj]==-1){
                    colour[adj] = !colour[curr];
                    q.push(adj);
                }
                else{
                    if(colour[adj]==colour[curr])
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colour(n, -1);
        for(int i =0;i<n;i++){
            if(colour[i]==-1){
                if(checkBfs(i, colour, graph)==false) 
                return false;
            }
        }
        return true;
    }
};
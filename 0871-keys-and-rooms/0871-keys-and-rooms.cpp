class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        queue<int> q;
        int n = rooms.size();
        q.push(0);
        vector<bool> visited(n, 0);
        int count = 1;
        visited[0] = true;
        while(!q.empty()){
            int currRoom = q.front();
            q.pop();
            
            for(int key:rooms[currRoom]){
                if(visited[key]==false){
                    q.push(key);
                    count++;
                    visited[key] = true;
                }
            }
        }
        return count==n;
    }
};
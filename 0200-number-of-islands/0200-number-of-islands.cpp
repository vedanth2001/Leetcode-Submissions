class Solution {
public:
    const vector<pair<int, int>> dir = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
    void processNeighbours(vector<vector<char>>& grid, vector<vector<int>> &visited, int row, int col){
        queue<pair<int, int>> q;
        visited[row][col] = 1;
        q.push({row, col});
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(auto newDir: dir){
                int nr = r + newDir.first;
                int nc = c + newDir.second;

                if(nr >= 0 && nr < grid.size() && nc >= 0 && nc < grid[0].size() && visited[nr][nc] == 0 && grid[nr][nc] == '1'){
                q.push({nr, nc});
                visited[nr][nc] = 1;
                }
            }
        }
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int islands = 0;
        vector<vector<int>> visited(n, vector<int>(m, 0));
        for(int i =0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited[i][j]==0 && grid[i][j] == '1'){
                    islands++;
                    processNeighbours(grid, visited, i, j);
                }
            }
        }
        return islands;
    }
};
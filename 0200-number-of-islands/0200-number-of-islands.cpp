class Solution {
public:
    void findBfs(vector<vector<char>>& grid, int row, int col, vector<vector<bool>> &vis){
        vis[row][col] = true;
        queue<pair<int, int>> q;
        int n = grid.size();
        int m = grid[0].size();
        q.push({row, col});
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            int dr[4] = {0, -1, 0, 1};
            int dc[4] = {-1, 0, 1, 0};


            for(int i =0;i<4;i++){
                int nrow = r + dr[i];
                int ncol = c + dc[i];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m 
                   && grid[nrow][ncol]=='1' && vis[nrow][ncol] == 0){
                    q.push({nrow, ncol});
                    vis[nrow][ncol] = true;
                } 
            }
        }
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        vector<vector<bool>> vis(n, vector<bool>(m,false));
        
        for(int i =0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(vis[i][j] == false && grid[i][j]=='1'){
                    findBfs(grid, i, j, vis);
                    count++;
                }
            }
        } 

        return count;
    }
};
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int tm = 0;
        int countFresh=0;
        int cnt=0;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<pair<int, int>, int>> q;


        for(int i =0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    vis[i][j]=2;
                    q.push({{i,j},0});
                }
                else if(grid[i][j]==1)countFresh++;
            }
        } 

        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();
            tm = max(t, tm);

            int dr[] = {0, 1, 0, -1};
            int dc[] = {-1, 0, 1, 0};


            for(int i=0;i<4;i++){
                int nrow = r + dr[i];
                int ncol = c + dc[i];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]!=2 && grid[nrow][ncol]==1){
                    q.push({{nrow,ncol},t+1});
                    vis[nrow][ncol]=2;
                    cnt++;
                }
            }
        }
        if(cnt!=countFresh) return -1;
        return tm;
        
    }
};
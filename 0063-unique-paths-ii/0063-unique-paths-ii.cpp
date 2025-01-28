class Solution {
public:
    int countPaths(vector<vector<int>>& obstacleGrid, int i, int j, vector<vector<int>> &mem){
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        if(mem[i][j] != -1) return mem[i][j];
        if (i >= n || j >= m) return 0;
        if(obstacleGrid[i][j]==1) return 0;
        if(i==n-1 && j==m-1) return 1;

        int right = countPaths(obstacleGrid, i, j+1, mem);
        int down = countPaths(obstacleGrid, i+1, j, mem);
        return mem[i][j] = right + down;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();

        vector<vector<int>> mem(n+1, vector<int>(m+1, -1));
        return countPaths(obstacleGrid, 0, 0, mem);
    }
};
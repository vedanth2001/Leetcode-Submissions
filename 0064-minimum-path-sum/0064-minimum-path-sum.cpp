class Solution {
public:
    int minPathSumHelper(vector<vector<int>>& grid, int i, int j, vector<vector<int>> &mem){
        int n = grid.size();
        int m = grid[0].size();
        if(i>=n || j>=m) return INT_MAX;
        if(mem[i][j]!=-1) return mem[i][j];
        if(i==n-1 && j==m-1) return grid[n-1][m-1];
         int right = minPathSumHelper(grid, i, j+1, mem);
        int down = minPathSumHelper(grid, i+1, j, mem);

        // Store result in memoization table
        return mem[i][j] = grid[i][j] + min(right, down);


        return mem[i][j];
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> mem(n, vector<int>(m, -1));
       return minPathSumHelper(grid, 0, 0, mem); 
    }
};
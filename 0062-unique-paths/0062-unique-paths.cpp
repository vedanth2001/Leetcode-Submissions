class Solution {
public:
    int countPaths(vector<vector<int>> &mem, int m, int n, int i, int j){
        if(i==m || j == n) return 0;
        if(i==m-1 && j==n-1) return 1;
        if(mem[i][j]!=-1) return mem[i][j];
        int right = countPaths(mem, m, n, i, j+1);
        int down = countPaths(mem, m, n, i+1, j);

        return mem[i][j] = right + down;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> mem(m+1, vector<int>(n+1, -1));
        return countPaths(mem, m, n, 0, 0);
    }
};
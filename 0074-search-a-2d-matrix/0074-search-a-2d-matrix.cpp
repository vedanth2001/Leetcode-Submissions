class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        //starting with top - right
        // [0][n-1]
        int r = 0;
        int c = n-1;
        
        while(r<m && c>=0){
            if(matrix[r][c] == target) return 1;

            if(matrix[r][c] > target) c--;

            else r++;
        }
        return 0;
    }
};
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> spiral;
        int rows = matrix.size();
        if (rows == 0) return spiral; // Handle empty matrix
        int cols = matrix[0].size();

        int top = 0;
        int right = cols - 1;
        int down = rows - 1;
        int left = 0;

        while (top <= down && left <= right) {
            // Traverse from left to right along the top row
            for (int i = left; i <= right; i++) {
                spiral.push_back(matrix[top][i]);
            }
            top++;

            // Traverse downwards along the right column
            for (int i = top; i <= down; i++) {
                spiral.push_back(matrix[i][right]);
            }
            right--;

            // Traverse from right to left along the bottom row (only if still within bounds)
            if (top <= down) {
                for (int i = right; i >= left; i--) {
                    spiral.push_back(matrix[down][i]);
                }
                down--;
            }

            // Traverse upwards along the left column (only if still within bounds)
            if (left <= right) {
                for (int i = down; i >= top; i--) {
                    spiral.push_back(matrix[i][left]);
                }
                left++;
            }
        }

        return spiral;
    }
};

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
    
        if (image[sr][sc] == color) return image;

        int originalColor = image[sr][sc];
        queue<pair<int, int>> q;
        q.push({sr, sc});
        vector<int> dr = {0, 1, 0, -1};
        vector<int> dc = {-1, 0, 1, 0};
        
        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            image[row][col] = color;

            for (int i = 0; i < 4; i++) {
                int nr = row + dr[i];
                int nc = col + dc[i];

                if (nr >= 0 && nc >= 0 && nr < n && nc < m && image[nr][nc] == originalColor) {
                    q.push({nr, nc});
                }
            }
            }
        return image;
    }
};
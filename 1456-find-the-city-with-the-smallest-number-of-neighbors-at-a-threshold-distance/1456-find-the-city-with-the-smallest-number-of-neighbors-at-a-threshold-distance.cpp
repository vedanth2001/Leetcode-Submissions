class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> mat(n, vector<int>(n, INT_MAX));
        int cityNo = 0;
        int countMin = INT_MAX;
        for(int i =0;i<n;i++) mat[i][i] = 0;

        for(auto &edge: edges){
            mat[edge[0]][edge[1]] = edge[2];
            mat[edge[1]][edge[0]] = edge[2];
        }

        for(int k = 0;k<n;k++){
            for(int i =0;i<n;i++){
                for(int j = 0;j<n;j++){
                    if(mat[i][k] == INT_MAX || mat[k][j] == INT_MAX){
                        continue;
                    }
                    mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
                }
            }
        }

        
        for(int i =0;i<n;i++){
            int count = 0;
            for(int j = 0;j<n;j++){
                if(mat[i][j] <= distanceThreshold)
                count++;
            }
            if (count < countMin || (count == countMin && i > cityNo)) {
                cityNo = i;
                countMin = count;
            }
        }
        return cityNo;
    }
};
class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(), cuts.end());
        
        // DP table
        vector<vector<int>> dp(c + 2, vector<int>(c + 2, 0));
        
        // Iterate over lengths of the subproblems
        for (int length = 1; length <= c; length++) {
            for (int i = 1; i <= c - length + 1; i++) {
                int j = i + length - 1;
                dp[i][j] = INT_MAX;
                for (int start = i; start <= j; start++) {
                    int cost = cuts[j + 1] - cuts[i - 1] + dp[i][start - 1] + dp[start + 1][j];
                    dp[i][j] = min(dp[i][j], cost);
                }
            }
        }
        
        return dp[1][c];
    }
};

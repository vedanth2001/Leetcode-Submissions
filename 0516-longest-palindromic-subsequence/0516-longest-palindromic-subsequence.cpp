class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string s2 = string(s.rbegin(), s.rend());
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return helper(s, s2, 0, 0, dp);
    }

    int helper(string &s1, string &s2, int i, int j, vector<vector<int>> &dp) {
        if (i >= s1.length() || j >= s2.length()) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        if (s1[i] == s2[j]) {
            dp[i][j] = 1 + helper(s1, s2, i + 1, j + 1, dp);
        } else {
            dp[i][j] = max(helper(s1, s2, i + 1, j, dp), helper(s1, s2, i, j + 1, dp));
        }
        return dp[i][j];
    }
};
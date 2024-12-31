class Solution {
public:
    int minDistanceHelper(string word1, string word2, int m, int n, vector<vector<int>> &mem){
        if(m==0) return n;
        if(n==0) return m;
        if(mem[m][n]!=-1) return mem[m][n];
        if(word1[m-1] == word2[n-1]) return minDistanceHelper(word1, word2, m-1, n-1, mem);
        mem[m][n] = 1 + min(minDistanceHelper(word1, word2, m-1, n, mem),
                       minDistanceHelper(word1, word2, m, n-1, mem));
        return mem[m][n];
    }
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> mem(m+1, vector<int>(n+1, -1));
        int distance = minDistanceHelper(word1, word2, m, n, mem);
        return distance;
    }
};
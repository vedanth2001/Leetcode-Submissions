class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int ans = 0;
        int n = s.size(), m = words.size();
        vector<vector<int>> vec(26);
        for(int i = 0; i < n; i++){
            vec[s[i] - 'a'].push_back(i);
        }
        
        for(int i = 0; i < m; i++){
            int k = -1; 
            bool isSubseq = true;
            for(int j = 0; j < words[i].size(); j++){
                int charIndex = words[i][j] - 'a';
                auto it = upper_bound(vec[charIndex].begin(), vec[charIndex].end(), k);
                if(it == vec[charIndex].end()) {
                    isSubseq = false;
                    break;
                } else {
                    k = *it; 
                }
            }
            ans += isSubseq;
        }
        
        return ans;
    }
};
auto init = [](){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return false;
}();
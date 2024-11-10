class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int count = 0;
        vector<int> prev(256, -1);
        int i =0;
        for(int j =0;j<n;j++){
        i = max(i, prev[s[j]] + 1);
        count = max(count, j-i+1);
        prev[s[j]] = j;     
        }
        return count;
    }
};
class Solution {
public:
    string longestPrefix(string s) {
        int n = s.length();
        vector<int> lps(n,0);
        lps[0] = 0;
        int len = 0;
        int i =1;
        while(i<n){
            if(s[i] == s[len]){
            lps[i] = ++len;
            i++;
            }
            else{
                if(len == 0){
                    lps[i]=0; i++;
                }
                else{
                    len=lps[len-1];
                }
            }
        }
        int longest = lps[n - 1];
        return s.substr(0, longest);
    }
};

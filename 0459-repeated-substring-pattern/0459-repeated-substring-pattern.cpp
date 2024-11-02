class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.length();
        int n1 = n/2;
        for(int i =1;i<=n1;i++){
            if(n%i==0){
                string sub = s.substr(0,i);
                string ans;

                for(int j =0;j<n/i;j++){
                    ans = ans + sub;
                }
                if(ans == s) return true;
            }
        }
        return false;
    }
};
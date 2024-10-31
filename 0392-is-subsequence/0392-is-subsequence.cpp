class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s==""){
            return true;
        }
        if(t=="" && s!="") return false;
        
        int n = s.length();
        int m = t.length();

        if(n>m) return false;
        
        int i = 0;
        int j = 0; 
        while(i<n && j<m){
            if(s[i]==t[j]){
                i++;
                j++;
            }
            else{
                j++;
            }
        }
        if(i==n) return true;
        return false;
        



    }
};
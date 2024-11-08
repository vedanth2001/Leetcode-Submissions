class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        int n = s.length();
        int m = p.length();
        if(n<m) return result;
        vector<int> countS(26,0);
        vector<int> countP(26,0);
        for(int i =0;i<m;i++){
            countS[s[i]-'a']++;
            countP[p[i]-'a']++;
        }
        for(int i =m;i<n;i++){
            if(countS==countP) result.push_back(i-m);
            countS[s[i-m]-'a']--;
            countS[s[i]-'a']++;
        }
        if(countS==countP) result.push_back(n-m);
        return result;
    }
};
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s2.length();
        int m = s1.length();
        if(n<m) return false;
        vector<int> countS1(26,0);
        vector<int> countS2(26,0);
        for(int i =0;i<m;i++){
            countS1[s1[i]-'a']++;
            countS2[s2[i]-'a']++;
        }
        for(int i =m;i<n;i++){
            if(countS1==countS2) return true;
            countS2[s2[i-m]-'a']--;
            countS2[s2[i]-'a']++;
        }
        if(countS1==countS2) return true;

        return false;
    }
};
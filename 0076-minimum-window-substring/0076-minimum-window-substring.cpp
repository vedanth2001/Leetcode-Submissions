class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();
        int m = t.length();
        int minLength = INT_MAX;
        int startI = -1;
        vector<int> map(256, 0);
        for(int i =0;i<m;i++){
            map[t[i]]++;
        }
        int l = 0;
        int r = 0;
        int count = 0;
        while(r<n){
            if(map[s[r]]>0) count = count + 1;
            map[s[r]]--;
            while(count == m){
                if(r-l+1 < minLength){
                    minLength = r-l+1;
                    startI = l;
                }
                map[s[l]]++;
                if(map[s[l]]>0) count = count - 1;
                l++;
            }
            r++;
        }
        if(startI == -1) return "";
        return s.substr(startI, minLength);

    }
};
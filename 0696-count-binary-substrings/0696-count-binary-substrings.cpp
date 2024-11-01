class Solution {
public:
    int countBinarySubstrings(string s) {
        vector<int> group;
        int count = 1;
        int result = 0;
        int n = s.length();
        for(int i =0;i<n-1;i++){
            if(s[i]==s[i+1]){
                count++;
            }
            else{
                group.push_back(count);
                count = 1;
            }
        }
        group.push_back(count);
        for(int i =0;i<group.size()-1;i++){
            result += min(group[i], group[i+1]);
        }
        return result;

    }
};
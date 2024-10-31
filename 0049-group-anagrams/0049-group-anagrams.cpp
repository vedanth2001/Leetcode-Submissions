class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        int n = strs.size();
        vector<string> sortedStrs(n);
        unordered_map<string, vector<int>> mp;
        sortedStrs=strs;
        for(int i =0;i<n;i++){
            sort(sortedStrs[i].begin(), sortedStrs[i].end());
        }
        for(int i =0;i<n;i++){
            mp[sortedStrs[i]].push_back(i);
        }
        for(auto& [str,list]: mp){
            vector<string> curr;
            int n = list.size();
            for(int i =0;i<n;i++){
                curr.push_back(strs[list[i]]);
            }
            result.push_back(curr);
        }
        return result;

        
    }
};
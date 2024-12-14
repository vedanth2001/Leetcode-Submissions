class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result;
        int n = nums.size();
        map<int, int> mp;
        priority_queue<pair<int, int>> pq;
        for(auto &num:nums){
            mp[num]++;
        }
        for(auto num:mp){
            pq.push({num.second, num.first});
        }
        while(k--){
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
};
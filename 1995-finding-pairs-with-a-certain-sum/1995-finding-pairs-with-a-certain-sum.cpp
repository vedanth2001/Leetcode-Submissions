class FindSumPairs {

private:
    vector<int> n1;
    vector<int> n2;
    unordered_map<int, int> mp;
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        n1= nums1;
        n2= nums2;
        for(auto nums:nums2){
            mp[nums]++;
        }
    }
    
    void add(int index, int val) {
        mp[n2[index]]--;
        n2[index]+=val;
        mp[n2[index]]++;
    }
    
    int count(int tot) {
        int count =0;
        int n =n1.size();
        for(int i =0;i<n;i++){
            if(mp.find(tot-n1[i])!=mp.end()){
                count+=mp[tot-n1[i]];
            }
        }
        return count;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> h;
        for(int i =0;i<n;i++){
            h.insert(nums[i]);
        }
        int res =0;
        int curr =1;
        for(auto num:h){
            if(h.find(num-1) == h.end()){
                int x = num;
                while(h.find(x+1)!=h.end()){
                    curr++;
                    x++;
                }
                res = max(curr, res);
                curr = 1;
            }
        }
        return res ;
    }
};
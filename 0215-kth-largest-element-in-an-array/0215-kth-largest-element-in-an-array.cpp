class Solution {
public:
    struct myComp{
    bool operator()(int a, int b) {
            return a > b;  
        }
    };
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<int, vector<int>, myComp> pq;
        for(int i =0;i<k;i++){
            pq.push(nums[i]);
        }
        for(int i=k;i<n;i++){
            if(nums[i] > pq.top()){
                pq.pop();
                pq.push(nums[i]);
            }
        }
        return pq.top();
    }
};
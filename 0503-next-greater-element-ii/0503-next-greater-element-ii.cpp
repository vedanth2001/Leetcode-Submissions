class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int nextGreater = INT_MIN;
        vector<int> result;
        // result.push_back(-1);
        int n = nums.size();
        stack<int> st;
        for (int i=n-1 ; i>=0 ; i--){
            while (!st.empty() && st.top() <= nums[i]){
                st.pop();
            }
            st.push(nums[i]);
        }
        for(int i =n-1;i>=0;i--){
            while(!st.empty() && st.top()<=nums[i]) 
            st.pop();

            if(st.empty()){
                result.push_back(-1);
            }   
            else result.push_back(st.top());

            st.push(nums[i]);
        }
        reverse(result.begin(), result.end());
        return result;

    }
};
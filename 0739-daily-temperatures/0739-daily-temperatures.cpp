class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> result(n);
        stack<int> nextGreater;
        for(int i =n-1;i>=0;i--){
            while(!nextGreater.empty() && temperatures[i]>=temperatures[nextGreater.top()])
            nextGreater.pop();

            if(nextGreater.empty()){
                result[i] = 0;
            }
            else{
                result[i] = nextGreater.top() - i;
            }
            nextGreater.push(i);
        }
        return result;
    }
};
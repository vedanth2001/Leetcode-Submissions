class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        priority_queue<pair<int, int>> pq;
        vector<int> result;
        for(int i =0;i<k;i++){
            pq.push({abs(arr[i]-x), i});
        }
        for(int i =k;i<n;i++){
            if(pq.top().first > abs(arr[i]-x)){
                pq.pop();
                pq.push({abs(arr[i]-x), i});
            }
        }
        while(!pq.empty()){
            result.push_back(arr[pq.top().second]);
            pq.pop();
        }
        sort(result.begin(), result.end());
        return result;

    }
};
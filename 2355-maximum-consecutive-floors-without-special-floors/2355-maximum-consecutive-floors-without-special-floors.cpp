class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        int n = special.size();
        sort(special.begin(), special.end());
        int maxFloors = max(0, special[0]-bottom);
        for(int i=1;i<n;i++){
            maxFloors = max(maxFloors, special[i]-special[i-1]-1);
        }
        maxFloors = max(maxFloors, top - special[n-1]);
        return maxFloors;
    }
};
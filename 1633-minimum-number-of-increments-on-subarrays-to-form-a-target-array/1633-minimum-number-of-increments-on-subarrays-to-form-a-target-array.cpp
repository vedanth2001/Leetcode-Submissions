class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int moves = target[0];
        int n = target.size();
        for(int i = 1;i<n;i++){
            if(target[i]>target[i-1]){
                moves += target[i]-target[i-1];
            }
        }
        return moves;
    }
};
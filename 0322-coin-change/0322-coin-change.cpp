class Solution {
public:
    int findChange(vector<int>& coins, int ind, int target, vector<vector<int>> &mem){
        if(target == 0) return 0;
        if (ind < 0 || target < 0) return INT_MAX;
        if(mem[ind][target]!=-1) return mem[ind][target];
        int take = INT_MAX;
        int notTake = findChange(coins, ind-1, target, mem);
        if(coins[ind]<=target){
            int res = findChange(coins, ind, target - coins[ind], mem);
            if (res != INT_MAX) take = 1 + res;
        }
        mem[ind][target] = min(notTake, take);
        return mem[ind][target];
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> mem(coins.size()+1, vector<int>(amount+1,-1));
        int res = findChange(coins, coins.size()-1, amount, mem);
        if(res==INT_MAX) return -1;

        return res;
    }
};
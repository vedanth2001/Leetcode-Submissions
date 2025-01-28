class Solution {
public:
    void calculate(vector<int> &nums, int i, vector<int> permutation, vector<vector<int>> &result){
        int n = nums.size();
        if(i==n) {
        result.push_back(nums); 
        return;
        }

        for(int j =i;j<n;j++){
            swap(nums[i], nums[j]);
            calculate(nums, i+1, permutation, result);
            swap(nums[i], nums[j]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();
        vector<int> permutation;
        calculate(nums, 0, permutation, result);
        return result;
    }
};
class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        return dfs(nums, 0, 0);
    }
    
    int dfs(vector<int>& nums, int index, int currentXor) {
        if(index == nums.size()) {
            return currentXor;
        }
        // Choice 1: exclude nums[index]
        int exclude = dfs(nums, index+1, currentXor);
        // Choice 2: include nums[index]
        int include = dfs(nums, index+1, currentXor ^ nums[index]);
        
        return exclude + include;
    }
};

class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int maxOR = 0;
        for(int x : nums) maxOR |= x;  // Step 1: overall max OR

        int count = 0;
        dfs(nums, 0, 0, maxOR, count);
        return count;
    }

    void dfs(vector<int>& nums, int index, int currentOR, int maxOR, int &count) {
        if(index == nums.size()) {
            if(currentOR == maxOR) count++;
            return;
        }
        // Choice 1: exclude nums[index]
        dfs(nums, index+1, currentOR, maxOR, count);
        // Choice 2: include nums[index]
        dfs(nums, index+1, currentOR | nums[index], maxOR, count);
    }
};

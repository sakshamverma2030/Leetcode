class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n = nums.size();
        for(int op = 0; op < k; op++) {
            // Step 1: find minimum element index
            int minIndex = 0;
            for(int i = 1; i < n; i++) {
                if(nums[i] < nums[minIndex]) {
                    minIndex = i;
                }
            }
            // Step 2: multiply and replace
            nums[minIndex] *= multiplier;
        }
        return nums;
    }
};

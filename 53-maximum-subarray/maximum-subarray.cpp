class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n);

        dp[0] = nums[0];  // base case
        int ans = dp[0];  // initialize answer

        for (int i = 1; i < n; i++) {
            dp[i] = max(nums[i], dp[i-1] + nums[i]);
            ans = max(ans, dp[i]);   // update global max
        }

        return ans;  // final answer
    }
};

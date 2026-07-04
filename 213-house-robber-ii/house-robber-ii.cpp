class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);

        vector<int> dp(n, 0), adp(n, 0);

        // Case 1: houses 0..n-2
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < n-1; i++) {
            dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
        }

        // Case 2: houses 1..n-1
        adp[1] = nums[1];
        adp[2] = max(nums[1], nums[2]);
        for (int i = 3; i < n; i++) {
            adp[i] = max(adp[i-1], adp[i-2] + nums[i]);
        }

        // Final answer
        return max(dp[n-2], adp[n-1]);
    }
};


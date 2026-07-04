class Solution {
public:
    int fib(int n) {
        // Base cases
        if (n == 0) return 0;   // Base case: F(0) = 0
        if (n == 1) return 1;   // Base case: F(1) = 1

        // DP array to store results
        vector<int> dp(n+1);
        dp[0] = 0;  // Base case
        dp[1] = 1;  // Base case

        // DP formula: F(i) = F(i-1) + F(i-2)
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[n];
    }};
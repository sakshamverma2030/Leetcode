class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> dp(n + 1, 0); // dp[i] = max score difference starting at i

        for (int i = n - 1; i >= 0; i--) {
            int take = 0;
            dp[i] = INT_MIN;
            for (int k = 1; k <= 3 && i + k <= n; k++) {
                take += stoneValue[i + k - 1];
                dp[i] = max(dp[i], take - dp[i + k]);
            }
        }

        if (dp[0] > 0) return "Alice";
        else if (dp[0] < 0) return "Bob";
        else return "Tie";
    }
};

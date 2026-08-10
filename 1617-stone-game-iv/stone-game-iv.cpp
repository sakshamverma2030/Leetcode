class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<bool> dp(n + 1, false);
        
        for (int i = 1; i <= n; ++i) {
            for (int k = 1; k * k <= i; ++k) {
                if (!dp[i - k * k]) {
                    dp[i] = true;
                    break; // Found at least one winning move
                }
            }
        }
        
        return dp[n];
    }
};
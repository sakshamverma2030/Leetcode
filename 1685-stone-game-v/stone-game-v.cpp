class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
       
        vector<int> pref(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            pref[i + 1] = pref[i] + stoneValue[i];
        }
        
        auto getSum = [&](int l, int r) {
            return pref[r + 1] - pref[l];
        };

        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int len = 2; len <= n; ++len) {
            for (int i = 0; i <= n - len; ++i) {
                int j = i + len - 1;
                
                for (int k = i; k < j; ++k) {
                    int leftSum = getSum(i, k);
                    int rightSum = getSum(k + 1, j);

                    if (leftSum < rightSum) {
                        dp[i][j] = max(dp[i][j], leftSum + dp[i][k]);
                    } else if (leftSum > rightSum) {
                        dp[i][j] = max(dp[i][j], rightSum + dp[k + 1][j]);
                    } else {
                        dp[i][j] = max(dp[i][j], leftSum + max(dp[i][k], dp[k + 1][j]));
                    }
                }
            }
        }

        return dp[0][n - 1];
    }
};
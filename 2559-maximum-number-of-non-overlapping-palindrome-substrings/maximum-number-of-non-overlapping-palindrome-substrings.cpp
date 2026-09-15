
class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.length();
        vector<int> dp(n + 1, 0);
        
        auto isPalindrome = [&](int l, int r) {
            while (l < r) {
                if (s[l++] != s[r--]) {
                    return false;
                }
            }
            return true;
        };
        
        for (int i = k; i <= n; ++i) {
            dp[i] = dp[i - 1];
            
            if (isPalindrome(i - k, i - 1)) {
                dp[i] = max(dp[i], 1 + dp[i - k]);
            }
            
            if (i > k && isPalindrome(i - k - 1, i - 1)) {
                dp[i] = max(dp[i], 1 + dp[i - k - 1]);
            }
        }
        
        return dp[n];
    }
};
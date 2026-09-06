class Solution {
public:
    int distinctSubseqII(string s) {
        const int MOD = 1e9 + 7;
        int n = s.size();
        vector<long long> dp(n+1, 0);
        vector<int> last(26, -1);

        dp[0] = 1; 

        for(int i=1; i<=n; i++) {
            dp[i] = (2 * dp[i-1]) % MOD;
            int ch = s[i-1] - 'a';
            if(last[ch] != -1) {
                dp[i] = (dp[i] - dp[last[ch]-1] + MOD) % MOD;
            }
            last[ch] = i;
        }

        return (dp[n] - 1 + MOD) % MOD; 
    }
};

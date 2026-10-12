class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        const long long MOD = 1e9 + 7;

        vector<long long> cnt(31, 0);

        for (int x : nums) {
            for (int b = 0; b < 31; b++) {
                if (x & (1LL << b))
                    cnt[b]++;
            }
        }

        long long ans = 0;

        for (int i = 0; i < k; i++) {
            long long cur = 0;

            for (int b = 0; b < 31; b++) {
                if (cnt[b] > 0) {
                    cur |= (1LL << b);
                    cnt[b]--;
                }
            }

            ans = (ans + (cur * cur) % MOD) % MOD;
        }

        return (int)ans;
    }
};
class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        const int MOD = 1e9 + 7;
        int m = s.size();

        // Precompute prefix arrays
        vector<long long> digitSum(m+1, 0), prefixX(m+1, 0), pow10(m+1, 1), nonZeroCount(m+1, 0);

        for (int i = 1; i <= m; i++) {
            pow10[i] = (pow10[i-1] * 10) % MOD;
        }

        for (int i = 0; i < m; i++) {
            int d = s[i] - '0';
            digitSum[i+1] = digitSum[i] + (d != 0 ? d : 0);
            nonZeroCount[i+1] = nonZeroCount[i] + (d != 0 ? 1 : 0);

            if (d != 0) {
                prefixX[i+1] = (prefixX[i] * 10 + d) % MOD;
            } else {
                prefixX[i+1] = prefixX[i];
            }
        }

        vector<int> ans;
        for (auto &qr : queries) {
            int l = qr[0], r = qr[1];

            // sum of digits in substring
            long long sumDigits = digitSum[r+1] - digitSum[l];

            // number of non-zero digits in substring
            int len = nonZeroCount[r+1] - nonZeroCount[l];

            // extract substring value
            long long x = (prefixX[r+1] - (prefixX[l] * pow10[len]) % MOD + MOD) % MOD;

            long long res = (x * sumDigits) % MOD;
            ans.push_back((int)res);
        }

        return ans;
    }
};

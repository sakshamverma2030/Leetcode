class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<long long> fact, invFact;

    long long modpow(long long a, long long b) {
        long long res = 1;
        while (b) {
            if (b & 1) res = res * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }
        return res;
    }

    void init(int n) {
        fact.resize(n+1);
        invFact.resize(n+1);
        fact[0] = 1;
        for (int i = 1; i <= n; i++) fact[i] = fact[i-1] * i % MOD;
        invFact[n] = modpow(fact[n], MOD-2);
        for (int i = n; i > 0; i--) invFact[i-1] = invFact[i] * i % MOD;
    }

    long long nCr(int n, int r) {
        if (r < 0 || r > n) return 0;
        return fact[n] * invFact[r] % MOD * invFact[n-r] % MOD;
    }

    int numberOfSets(int n, int k) {
        init(n+k); 
        return (int)nCr(n+k-1, 2*k);
    }
};

#include <vector>
#include <numeric>
#include <algorithm>
#include <cstring>

class Solution {
private:
    const int MOD = 1e9 + 7;
    // Max constraints: N <= 200, Max value <= 200
    int memo[201][201][201];

    int solve(int i, int x, int y, const std::vector<int>& nums) {
        // Base case: processed all elements
        if (i == nums.size()) {
            return (x > 0 && x == y) ? 1 : 0;
        }

        // Return cached result if already computed
        if (memo[i][x][y] != -1) {
            return memo[i][x][y];
        }

        // Choice 1: Skip nums[i]
        long long ans = solve(i + 1, x, y, nums);

        // Choice 2: Add nums[i] to seq1
        ans = (ans + solve(i + 1, std::gcd(x, nums[i]), y, nums)) % MOD;

        // Choice 3: Add nums[i] to seq2
        ans = (ans + solve(i + 1, x, std::gcd(y, nums[i]), nums)) % MOD;

        return memo[i][x][y] = ans;
    }

public:
    int subsequencePairCount(std::vector<int>& nums) {
        // Initialize the memoization table with -1
        std::memset(memo, -1, sizeof(memo));
        return solve(0, 0, 0, nums);
    }
};
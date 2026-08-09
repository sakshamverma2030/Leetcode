#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        
        // suffix_sum[i] stores the total stones from piles[i] to piles[n-1]
        vector<int> suffix_sum(n + 1, 0);
        for (int i = n - 1; i >= 0; --i) {
            suffix_sum[i] = suffix_sum[i + 1] + piles[i];
        }

        // dp[i][M] = max stones the current player can collect 
        // starting at index i with parameter M
        vector<vector<int>> memo(n, vector<int>(n + 1, 0));

        auto solve = [&](auto& self, int i, int M) -> int {
            // Base Case: If remaining piles are <= 2M, take all remaining piles
            if (i + 2 * M >= n) {
                return suffix_sum[i];
            }

            if (memo[i][M] != 0) {
                return memo[i][M];
            }

            int max_stones = 0;
            // Try taking X piles where 1 <= X <= 2M
            for (int X = 1; X <= 2 * M; ++X) {
                int next_M = max(M, X);
                int opponent_score = self(self, i + X, next_M);
                int current_score = suffix_sum[i] - opponent_score;
                
                max_stones = max(max_stones, current_score);
            }

            return memo[i][M] = max_stones;
        };

        return solve(solve, 0, 1);
    }
};
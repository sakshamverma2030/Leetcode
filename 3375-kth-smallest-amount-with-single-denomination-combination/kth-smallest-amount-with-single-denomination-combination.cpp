#include <vector>
#include <numeric>
#include <algorithm>

class Solution {
public:
    long long findKthSmallest(std::vector<int>& coins, int k) {
        int n = coins.size();
        
        // Helper function to count valid amounts <= target using Inclusion-Exclusion
        auto count = [&](long long target) -> long long {
            long long total = 0;
            // Iterate through all 2^n - 1 non-empty subsets
            for (int mask = 1; mask < (1 << n); ++mask) {
                long long current_lcm = 1;
                int bits = 0;
                
                for (int i = 0; i < n; ++i) {
                    if ((mask >> i) & 1) {
                        bits++;
                        current_lcm = std::lcm(current_lcm, (long long)coins[i]);
                    }
                }
                
                if (bits % 2 == 1) {
                    total += target / current_lcm;
                } else {
                    total -= target / current_lcm;
                }
            }
            return total;
        };

        // Binary Search range
        long long low = 1;
        long long high = 1LL * (*std::min_element(coins.begin(), coins.end())) * k;
        long long ans = high;

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (count(mid) >= k) {
                ans = mid;
                high = mid - 1; // Try to find a smaller valid value
            } else {
                low = mid + 1;  // Need a larger value
            }
        }

        return ans;
    }
};
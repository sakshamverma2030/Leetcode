#include <vector>
#include <unordered_set>
#include <algorithm>

class Solution {
public:
    int uniqueXorTriplets(std::vector<int>& nums) {
        int n = nums.size();
        
        // Step 1: Collect unique single elements
        std::vector<int> unique_nums;
        std::vector<bool> has_single(2048, false);
        for (int x : nums) {
            if (!has_single[x]) {
                has_single[x] = true;
                unique_nums.push_back(x);
            }
        }
        
        // Step 2: Find all unique pair XOR values
        std::vector<bool> has_pair(2048, false);
        std::vector<int> unique_pairs;
        
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                int pair_xor = nums[i] ^ nums[j];
                if (!has_pair[pair_xor]) {
                    has_pair[pair_xor] = true;
                    unique_pairs.push_back(pair_xor);
                }
            }
        }
        
        // Step 3: Find all unique triplet XOR values
        std::vector<bool> has_triplet(2048, false);
        int unique_triplets_count = 0;
        
        for (int p : unique_pairs) {
            for (int x : unique_nums) {
                int triplet_xor = p ^ x;
                if (!has_triplet[triplet_xor]) {
                    has_triplet[triplet_xor] = true;
                    unique_triplets_count++;
                }
            }
        }
        
        return unique_triplets_count;
    }
};
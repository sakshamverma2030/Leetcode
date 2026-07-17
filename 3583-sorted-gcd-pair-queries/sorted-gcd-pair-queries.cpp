class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int n = nums.size();
        int maxVal = *max_element(nums.begin(), nums.end());

        // Step 1: frequency of each number
        vector<int> freq(maxVal + 1, 0);
        for (int x : nums) freq[x]++;

        // Step 2: count how many numbers divisible by g
        vector<long long> cnt(maxVal + 1, 0);
        for (int g = 1; g <= maxVal; g++) {
            for (int multiple = g; multiple <= maxVal; multiple += g) {
                cnt[g] += freq[multiple];
            }
        }

        // Step 3: exact gcd count using inclusion-exclusion
        vector<long long> exact(maxVal + 1, 0);
        for (int g = maxVal; g >= 1; g--) {
            long long totalPairs = cnt[g] * (cnt[g] - 1) / 2;
            for (int k = 2 * g; k <= maxVal; k += g) {
                totalPairs -= exact[k];
            }
            exact[g] = totalPairs;
        }

        // Step 4: prefix sums of counts
        vector<long long> prefix;
        vector<int> values; // store gcd values
        long long sum = 0;
        for (int g = 1; g <= maxVal; g++) {
            if (exact[g] > 0) {
                sum += exact[g];
                prefix.push_back(sum);
                values.push_back(g);
            }
        }

        // Step 5: answer queries via binary search
        vector<int> ans;
        for (long long q : queries) {
            int idx = lower_bound(prefix.begin(), prefix.end(), q + 1) - prefix.begin();
            ans.push_back(values[idx]);
        }
        return ans;
    }
};

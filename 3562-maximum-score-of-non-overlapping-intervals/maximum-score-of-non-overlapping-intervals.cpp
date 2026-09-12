#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

class Solution {
    struct State {
        long long weight = 0;
        vector<int> selected;
    };

    // Helper comparison: returns true if 'a' is strictly better than 'b'
    bool isBetter(const State& a, const State& b) {
        if (a.weight != b.weight) {
            return a.weight > b.weight;
        }
        return a.selected < b.selected; // Lexicographically smaller vector of indices
    }

public:
    vector<int> maximumWeight(vector<vector<int>>& rawIntervals) {
        int n = rawIntervals.size();
        
        // {left, right, weight, original_index}
        vector<tuple<int, int, int, int>> intervals(n);
        for (int i = 0; i < n; ++i) {
            intervals[i] = {rawIntervals[i][0], rawIntervals[i][1], rawIntervals[i][2], i};
        }

        // Sort by start position (left)
        sort(intervals.begin(), intervals.end());

        // memo[i][quota] initialized with weight -1
        vector<vector<State>> memo(n, vector<State>(5, {-1, {}}));

        auto dp = [&](auto& self, int i, int quota) -> State {
            if (i == n || quota == 0) return {0, {}};
            if (memo[i][quota].weight != -1) return memo[i][quota];

            // Option 1: Skip interval i
            State skip = self(self, i + 1, quota);

            // Option 2: Pick interval i
            auto [l, r, weight, origIndex] = intervals[i];

            // Binary search for first interval starting strictly after current interval's right endpoint 'r'
            int low = i + 1, high = n, nextIdx = n;
            while (low < high) {
                int mid = low + (high - low) / 2;
                if (get<0>(intervals[mid]) > r) {
                    nextIdx = mid;
                    high = mid;
                } else {
                    low = mid + 1;
                }
            }

            State nextRes = self(self, nextIdx, quota - 1);
            State pick;
            pick.weight = weight + nextRes.weight;
            pick.selected = nextRes.selected;
            pick.selected.push_back(origIndex);
            
            // Indices in the final result must be sorted
            sort(pick.selected.begin(), pick.selected.end());

            return memo[i][quota] = isBetter(pick, skip) ? pick : skip;
        };

        return dp(dp, 0, 4).selected;
    }
};
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        // 1. Pair each value with its original index and sort by value
        vector<pair<int, int>> sorted_nodes(n);
        for (int i = 0; i < n; ++i) {
            sorted_nodes[i] = {nums[i], i};
        }
        sort(sorted_nodes.begin(), sorted_nodes.end());
        
        // Map from original index to its new position in the sorted array
        vector<int> orig_to_sorted(n);
        for (int i = 0; i < n; ++i) {
            orig_to_sorted[sorted_nodes[i].second] = i;
        }
        
        // 2. Compute component IDs to identify disconnected blocks
        vector<int> components(n, 0);
        int comp_id = 0;
        for (int i = 1; i < n; ++i) {
            if (sorted_nodes[i].first - sorted_nodes[i - 1].first > maxDiff) {
                comp_id++;
            }
            components[i] = comp_id;
        }
        
        // 3. Build Binary Lifting Table
        // 2^17 = 131,072 > 10^5, so 18 rows is perfectly sufficient
        int LOG = 18;
        vector<vector<int>> up(n, vector<int>(LOG, 0));
        
        // Initialize 2^0 steps using a sliding window
        int r = 0;
        for (int l = 0; l < n; ++l) {
            while (r < n && sorted_nodes[r].first - sorted_nodes[l].first <= maxDiff) {
                r++;
            }
            up[l][0] = r - 1; // Furthest node reachable from 'l' in 1 step
        }
        
        // Fill out the binary lifting table for 2^j jumps
        for (int j = 1; j < LOG; ++j) {
            for (int i = 0; i < n; ++i) {
                up[i][j] = up[up[i][j - 1]][j - 1];
            }
        }
        
        // 4. Process Queries
        vector<int> ans;
        ans.reserve(queries.size());
        
        for (const auto& q : queries) {
            int u = q[0];
            int v = q[1];
            
            if (u == v) {
                ans.push_back(0);
                continue;
            }
            
            int su = orig_to_sorted[u];
            int sv = orig_to_sorted[v];
            
            // Normalize so we always move left-to-right (smaller to larger index)
            if (su > sv) {
                swap(su, sv);
            }
            
            // If they are in different components, they are completely unreachable
            if (components[su] != components[sv]) {
                ans.push_back(-1);
                continue;
            }
            
            int steps = 0;
            int curr = su;
            
            // Binary lift as far right as possible without reaching or passing 'sv'
            for (int j = LOG - 1; j >= 0; --j) {
                if (up[curr][j] < sv) {
                    curr = up[curr][j];
                    steps += (1 << j);
                }
            }
            
            // One final step will bridge the gap to reach or exceed 'sv'
            steps += 1;
            ans.push_back(steps);
        }
        
        return ans;
    }
};
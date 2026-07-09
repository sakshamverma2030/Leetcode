class Solution {
public:
    struct DSU {
        vector<int> parent;
        DSU(int n) {
            parent.resize(n);
            iota(parent.begin(), parent.end(), 0);
        }
        int find(int x) {
            if (parent[x] != x) parent[x] = find(parent[x]);
            return parent[x];
        }
        void unite(int x, int y) {
            x = find(x); y = find(y);
            if (x != y) parent[y] = x;
        }
    };

    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        DSU dsu(n);

        // Step 1: Build connected components
        for (int i = 0; i < n - 1; i++) {
            if (nums[i+1] - nums[i] <= maxDiff) {
                dsu.unite(i, i+1);
            }
        }

        // Step 2: Answer queries
        vector<bool> ans;
        ans.reserve(queries.size());
        for (auto &q : queries) {
            ans.push_back(dsu.find(q[0]) == dsu.find(q[1]));
        }
        return ans;
    }
};

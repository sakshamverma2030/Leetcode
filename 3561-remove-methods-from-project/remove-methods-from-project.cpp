class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        // Step 1: Build adjacency list
        vector<vector<int>> adj(n);
        for (auto &edge : invocations) {
            adj[edge[0]].push_back(edge[1]);
        }

        // Step 2: Find suspicious set (reachable from k)
        vector<bool> suspicious(n, false);
        queue<int> q;
        q.push(k);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            if (suspicious[u]) continue;
            suspicious[u] = true;
            for (int v : adj[u]) {
                if (!suspicious[v]) q.push(v);
            }
        }

        // Step 3: Check external invocations into suspicious set
        for (auto &edge : invocations) {
            int a = edge[0], b = edge[1];
            if (suspicious[b] && !suspicious[a]) {
                // Outside method invokes suspicious → cannot remove
                vector<int> all;
                for (int i = 0; i < n; i++) all.push_back(i);
                return all;
            }
        }

        // Step 4: Return remaining methods
        vector<int> result;
        for (int i = 0; i < n; i++) {
            if (!suspicious[i]) result.push_back(i);
        }
        return result;
    }
};

#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        // adjacency list
        vector<vector<pair<int,int>>> adj(n+1);
        for (auto &r : roads) {
            adj[r[0]].push_back({r[1], r[2]});
            adj[r[1]].push_back({r[0], r[2]});
        }

        // BFS/DFS from city 1
        vector<bool> visited(n+1, false);
        int ans = INT_MAX;
        dfs(1, adj, visited, ans);
        return ans;
    }

    void dfs(int node, vector<vector<pair<int,int>>>& adj, vector<bool>& visited, int &ans) {
        visited[node] = true;
        for (auto &nbr : adj[node]) {
            ans = min(ans, nbr.second); // update min edge
            if (!visited[nbr.first]) {
                dfs(nbr.first, adj, visited, ans);
            }
        }
    }
};

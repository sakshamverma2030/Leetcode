class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        queue<pair<int,int>> q;

        // Step 1: Multi-source BFS from thieves
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    dist[i][j] = 0;
                    q.push({i,j});
                }
            }
        }

        vector<int> dr = {1,-1,0,0};
        vector<int> dc = {0,0,1,-1};

        while (!q.empty()) {
            auto [r,c] = q.front(); q.pop();
            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k], nc = c + dc[k];
                if (nr>=0 && nr<n && nc>=0 && nc<n && dist[nr][nc] == INT_MAX) {
                    dist[nr][nc] = dist[r][c] + 1;
                    q.push({nr,nc});
                }
            }
        }

        // Step 2: Max-Heap BFS (maximize minimum distance)
        priority_queue<pair<int,pair<int,int>>> pq;
        vector<vector<int>> seen(n, vector<int>(n, 0));
        pq.push({dist[0][0], {0,0}});
        seen[0][0] = 1;

        while (!pq.empty()) {
            auto [safe, pos] = pq.top(); pq.pop();
            int r = pos.first, c = pos.second;

            if (r == n-1 && c == n-1) return safe;

            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k], nc = c + dc[k];
                if (nr>=0 && nr<n && nc>=0 && nc<n && !seen[nr][nc]) {
                    seen[nr][nc] = 1;
                    pq.push({min(safe, dist[nr][nc]), {nr,nc}});
                }
            }
        }

        return 0;
    }
};

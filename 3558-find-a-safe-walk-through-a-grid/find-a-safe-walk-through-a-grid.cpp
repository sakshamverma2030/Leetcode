class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, -1));

        queue<tuple<int,int,int>> q; // (row, col, health)
        q.push({0,0,health - grid[0][0]});
        visited[0][0] = health - grid[0][0];

        vector<int> dr = {1,-1,0,0};
        vector<int> dc = {0,0,1,-1};

        while (!q.empty()) {
            auto [r,c,h] = q.front(); q.pop();

            if (h <= 0) continue; // health khatam
            if (r == m-1 && c == n-1) return true; // destination reached

            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k], nc = c + dc[k];
                if (nr>=0 && nr<m && nc>=0 && nc<n) {
                    int nh = h - grid[nr][nc];
                    if (nh > visited[nr][nc]) {
                        visited[nr][nc] = nh;
                        q.push({nr,nc,nh});
                    }
                }
            }
        }

        return false;
    }
};

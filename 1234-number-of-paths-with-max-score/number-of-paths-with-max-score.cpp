class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        const int MOD = 1e9+7;
        vector<vector<int>> score(n, vector<int>(n, -1));
        vector<vector<int>> ways(n, vector<int>(n, 0));
        
        score[n-1][n-1] = 0; // 'S' start
        ways[n-1][n-1] = 1;
        
        for(int i=n-1; i>=0; i--){
            for(int j=n-1; j>=0; j--){
                if(board[i][j] == 'X' || (i==n-1 && j==n-1)) continue;
                
                int best = -1, cnt = 0;
                vector<pair<int,int>> dirs = {{i+1,j},{i,j+1},{i+1,j+1}};
                
                for(auto [x,y]: dirs){
                    if(x<n && y<n && score[x][y] != -1){
                        if(score[x][y] > best){
                            best = score[x][y];
                            cnt = ways[x][y];
                        } else if(score[x][y] == best){
                            cnt = (cnt + ways[x][y]) % MOD;
                        }
                    }
                }
                
                if(best != -1){
                    score[i][j] = best + (isdigit(board[i][j]) ? board[i][j]-'0' : 0);
                    ways[i][j] = cnt;
                }
            }
        }
        
        if(score[0][0] == -1) return {0,0};
        return {score[0][0], ways[0][0]};
    }
};

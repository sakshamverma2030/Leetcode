class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        int m = s.size();
        vector<int> ans(m, 0);
        
        for (int i = 0; i < m; i++) {
            int r = startPos[0], c = startPos[1];
            int count = 0;
            
            for (int j = i; j < m; j++) {
                if (s[j] == 'L') c--;
                else if (s[j] == 'R') c++;
                else if (s[j] == 'U') r--;
                else if (s[j] == 'D') r++;
                
                if (r < 0 || r >= n || c < 0 || c >= n) break;
                count++;
            }
            ans[i] = count;
        }
        
        return ans;
    }
};

class Solution {
public:
    int minDistance(string s1, string s2) 
    {
        int m = s1.length();
        int n = s2.length();

        // DP table: t[i][j] = min operations to convert s1[0..i-1] → s2[0..j-1]
        vector<vector<int>> t(m+1, vector<int>(n+1));

        for(int i = 0; i <= m; i++) {
            for(int j = 0; j <= n; j++) {
                if(i == 0 || j == 0) {
                    // Base case: if one string is empty
                    t[i][j] = i + j;
                } 
                else if(s1[i-1] == s2[j-1]) {
                    // Characters match → no new operation
                    t[i][j] = t[i-1][j-1];
                } 
                else {
                    // Characters differ → choose min of insert, delete, replace
                    t[i][j] = 1 + min({t[i][j-1],   // insert
                                       t[i-1][j],   // delete
                                       t[i-1][j-1]  // replace
                                      });
                }
            }
        }

        return t[m][n];
    }
};
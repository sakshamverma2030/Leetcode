class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();
        int count = 0;
        
        for (int c = 0; c < m; c++) {
            for (int r = 0; r < n - 1; r++) {
                if (strs[r][c] > strs[r + 1][c]) {
                    count++;
                    break; // move to next column
                }
            }
        }
        
        return count;
    }
};

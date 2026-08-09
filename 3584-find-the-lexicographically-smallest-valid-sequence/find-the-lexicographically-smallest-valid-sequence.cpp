#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();

        // last_pos[j] stores the maximum index in word1 
        // to match word2[j...m-1] as a valid suffix subsequence
        vector<int> last_pos(m, -1);
        
        int p = n - 1;
        for (int j = m - 1; j >= 0; --j) {
            while (p >= 0 && word1[p] != word2[j]) {
                p--;
            }
            if (p >= 0) {
                last_pos[j] = p;
                p--; // Move to previous position in word1 for next suffix char
            }
        }

        vector<int> ans;
        bool used_change = false;
        int j = 0; // Pointer for word2

        for (int i = 0; i < n && j < m; ++i) {
            if (word1[i] == word2[j]) {
                ans.push_back(i);
                j++;
            } else if (!used_change) {
                // Check if skipping/changing word1[i] to match word2[j] 
                // leaves enough remaining positions in word1 to match word2[j+1...m-1]
                if (j + 1 == m || (i + 1 <= last_pos[j + 1])) {
                    ans.push_back(i);
                    used_change = true;
                    j++;
                }
            }
        }

        if (ans.size() == m) {
            return ans;
        }
        return {};
    }
};
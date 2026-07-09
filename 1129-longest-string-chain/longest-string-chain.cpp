class Solution {
public:
    // Check if prev is predecessor of curr
    bool isPred(string &prev, string &curr) {
        if (curr.size() != prev.size() + 1) return false;
        int i = 0, j = 0;
        while (i < prev.size() && j < curr.size()) {
            if (prev[i] == curr[j]) {
                i++; j++;
            } else {
                j++; // skip one char in curr
            }
        }
        return i == prev.size();
    }

    // Sort words by length
    static bool cmp(string &a, string &b) {
        return a.size() < b.size();
    }

    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), cmp);
        int n = words.size();

        vector<int> dp(n, 1);
        int maxL = 1;

        // Outer loop: each word
        for (int i = 0; i < n; i++) {
            // Inner loop: check all smaller words
            for (int j = 0; j < i; j++) {
                if (isPred(words[j], words[i])) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            maxL = max(maxL, dp[i]);
        }
        return maxL;
    }
};

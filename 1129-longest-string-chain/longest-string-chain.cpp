class Solution {
public:
    // Check if prev is predecessor of curr
    bool isPred(string &prev, string &curr) {
        if (curr.size() != prev.size() + 1) return false;
        int i = 0, j = 0;
        while (i < prev.size() && j < curr.size()) {
            if (prev[i] == curr[j]) { i++; j++; }
            else { j++; }
        }
        return i == prev.size();
    }

    // Sort words by length
    static bool myFunction(string &word1, string &word2) {
        return word1.size() < word2.size();
    }

    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(), myFunction);

        vector<int> t(n, 1);
        int maxL = 1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (isPred(words[j], words[i])) {
                    t[i] = max(t[i], t[j] + 1);
                }
            }
            maxL = max(maxL, t[i]);
        }
        return maxL;
    }
};

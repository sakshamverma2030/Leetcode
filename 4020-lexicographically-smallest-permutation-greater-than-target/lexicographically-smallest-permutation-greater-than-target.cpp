class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        vector<int> freq(26, 0);
        for (char c : s) freq[c - 'a']++;

        string ans;
        if (dfs(0, true, freq, target, ans)) return ans;
        return "";
    }

    bool dfs(int pos, bool tight, vector<int>& freq, string& target, string& ans) {
        if (pos == target.size()) return !tight; // must be strictly greater

        for (int ch = 0; ch < 26; ch++) {
            if (freq[ch] == 0) continue;
            char c = 'a' + ch;

            if (tight) {
                if (c < target[pos]) continue;
                freq[ch]--;
                ans.push_back(c);

                if (c == target[pos]) {
                    if (dfs(pos + 1, true, freq, target, ans)) return true;
                } else { 
                    // c > target[pos], fill rest greedily
                    string backup = ans;
                    vector<int> f = freq;
                    for (int i = 0; i < 26; i++) {
                        while (f[i]--) backup.push_back('a' + i);
                    }
                    ans = backup;
                    return true;
                }

                ans.pop_back();
                freq[ch]++;
            } else {
                // already greater, fill smallest
                freq[ch]--;
                ans.push_back(c);
                if (dfs(pos + 1, false, freq, target, ans)) return true;
                ans.pop_back();
                freq[ch]++;
            }
        }
        return false;
    }
};

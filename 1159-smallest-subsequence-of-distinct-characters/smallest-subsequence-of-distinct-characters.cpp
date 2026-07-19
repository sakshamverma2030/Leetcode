class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> freq(26, 0);
        vector<bool> inStack(26, false);

        // frequency count
        for (char c : s) freq[c - 'a']++;

        string result = "";
        for (char c : s) {
            freq[c - 'a']--;

            if (inStack[c - 'a']) continue;

            // maintain lexicographically smallest order
            while (!result.empty() && result.back() > c && freq[result.back() - 'a'] > 0) {
                inStack[result.back() - 'a'] = false;
                result.pop_back();
            }

            result.push_back(c);
            inStack[c - 'a'] = true;
        }

        return result;
    }
};


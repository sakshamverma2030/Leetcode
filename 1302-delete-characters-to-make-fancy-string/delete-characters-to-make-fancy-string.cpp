class Solution {
public:
    string makeFancyString(string s) {
        string ans;
        for (char c : s) {
            int n = ans.size();
            if (n >= 2 && ans[n-1] == c && ans[n-2] == c) {
                // skip this character to avoid 3 consecutive same
                continue;
            }
            ans.push_back(c);
        }
        return ans;
    }
};

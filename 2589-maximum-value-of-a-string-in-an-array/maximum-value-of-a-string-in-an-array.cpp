class Solution {
public:
    int maximumValue(vector<string>& strs) {
        int ans = 0;
        for (string &s : strs) {
            bool isDigit = true;
            for (char c : s) {
                if (!isdigit(c)) {
                    isDigit = false;
                    break;
                }
            }
            int val = isDigit ? stoi(s) : (int)s.size();
            ans = max(ans, val);
        }
        return ans;
    }
};

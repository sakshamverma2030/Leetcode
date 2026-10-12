class Solution {
public:
    vector<string> ans;

    void dfs(int idx, string &digits, string &curr,
             vector<string> &mp) {

        if (idx == digits.size()) {
            ans.push_back(curr);
            return;
        }

        string letters = mp[digits[idx] - '0'];

        for (char ch : letters) {
            curr.push_back(ch);
            dfs(idx + 1, digits, curr, mp);
            curr.pop_back(); 
        }
    }

    vector<string> letterCombinations(string digits) {

        if (digits.empty()) return {};

        vector<string> mp = {
            "", "", "abc", "def", "ghi",
            "jkl", "mno", "pqrs", "tuv", "wxyz"
        };

        string curr;

        dfs(0, digits, curr, mp);

        return ans;
    }
};
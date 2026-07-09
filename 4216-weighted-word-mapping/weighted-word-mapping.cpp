class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans;
        for (auto &word : words) {
            int sum = 0;
            for (char c : word) {
                sum += weights[c - 'a'];
            }
            int modVal = sum % 26;
            char mappedChar = 'z' - modVal; // reverse alphabetical mapping
            ans.push_back(mappedChar);
        }
        return ans;
    }
};

class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        int n = s.size();
        string ans(n, ' ');   // n size ka empty string banate hain

        for (int i = 0; i < n; i++) {
            ans[indices[i]] = s[i];   // har character ko uske naya position pe daal do
        }

        return ans;
    }
};

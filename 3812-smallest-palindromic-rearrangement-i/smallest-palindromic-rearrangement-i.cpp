class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> freq(26, 0);
        for (char c : s) freq[c - 'a']++;

        string half = "", mid = "";
        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2) mid = string(1, 'a' + i);
            half += string(freq[i] / 2, 'a' + i);
        }
        string rev = half; reverse(rev.begin(), rev.end());
        return half + mid + rev;
    }
};

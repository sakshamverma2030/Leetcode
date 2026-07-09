class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_set<char> broken(brokenLetters.begin(), brokenLetters.end());
        int ans = 0;
        
        stringstream ss(text);
        string word;
        
        while (ss >> word) {
            bool valid = true;
            for (char c : word) {
                if (broken.count(c)) {
                    valid = false;
                    break;
                }
            }
            if (valid) ans++;
        }
        
        return ans;
    }
};

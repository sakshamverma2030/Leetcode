class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        int n = words.size();
        int count = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                string rev = words[j];
                reverse(rev.begin(), rev.end());
                if(words[i] == rev) {
                    count++;
                }
            }
        }
        return count;
    }
};

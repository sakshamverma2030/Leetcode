class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char,int> freq;
        int left = 0, maxLen = 0;
        
        for(int right = 0; right < s.size(); right++) {
            freq[s[right]]++;
            
            // shrink window if any char > 2
            while(freq[s[right]] > 2) {
                freq[s[left]]--;
                left++;
            }
            
            maxLen = max(maxLen, right - left + 1);
        }
        
        return maxLen;
    }
};

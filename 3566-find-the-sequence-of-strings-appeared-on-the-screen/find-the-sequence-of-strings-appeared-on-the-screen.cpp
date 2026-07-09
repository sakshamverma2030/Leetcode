class Solution {
public:
    vector<string> stringSequence(string target) {
        vector<string> ans;
        string curr = "";
        
        for (char ch : target) {
            // Step 1: append 'a'
            curr.push_back('a');
            ans.push_back(curr);
            
            // Step 2: increment last char until it matches target char
            while (curr.back() != ch) {
                if (curr.back() == 'z') curr.back() = 'a';
                else curr.back()++;
                ans.push_back(curr);
            }
        }
        
        return ans;
    }
};

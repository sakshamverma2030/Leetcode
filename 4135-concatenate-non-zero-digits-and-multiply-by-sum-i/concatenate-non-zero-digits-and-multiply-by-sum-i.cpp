class Solution {
public:
    long long sumAndMultiply(int n) {
        string s = to_string(n);
        string filtered = "";
        
        // Step 1: filter non-zero digits
        for (char c : s) {
            if (c != '0') filtered += c;
        }
        
        // Step 2: handle edge case
        if (filtered.empty()) return 0;
        
        // Step 3: convert to integer
        long long x = stoll(filtered);
        
        // Step 4: calculate sum of digits
        long long sum = 0;
        for (char c : filtered) {
            sum += (c - '0');
        }
        
        // Step 5: return result
        return x * sum;
    }
};

class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;
        for (int k = 1; k <= 5; k++) { 
            long long low = 1;
            for (int i = 0; i < 3 * k; i++) low *= 10; 
            long long high = 1;
            for (int i = 0; i < 3 * (k + 1); i++) high *= 10; 
            high -= 1;
            
            if (n >= low) {
                ans += k * (min(n, high) - low + 1);
            }
        }
        return ans;
    }
};

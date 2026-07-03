class Solution {
public:
    int fib(int n) {
        // Base cases
        if (n == 0) return 0;   // Base case: F(0) = 0
        if (n == 1) return 1;   // Base case: F(1) = 1

        int prev2 = 0;  // F(0)
        int prev1 = 1;  // F(1)
        int cur;

        // DP formula but without array
        for (int i = 2; i <= n; i++) {
            cur = prev1 + prev2;   // F(i) = F(i-1) + F(i-2)
            prev2 = prev1;
            prev1 = cur;
        }
        return prev1;
    }
};
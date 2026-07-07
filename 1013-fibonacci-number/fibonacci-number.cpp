class Solution {
public:
    int fib(int n) {
        // Base cases
        if (n == 0) return 0;   // Base case: F(0) = 0
        if (n == 1) return 1;   // Base case: F(1) = 1

        return fib(n-1) + fib(n-2);

    }};
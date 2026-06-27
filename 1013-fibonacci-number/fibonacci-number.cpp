class Solution {
public:
    int fib(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;

        int f[n+1];   // array banaya Isliye array banaya jaata hai, taaki har index par us Fibonacci number ki value rakhi ja sake.
        f[0] = 0;
        f[1] = 1;

        for (int i = 2; i <= n; i++) {
            f[i] = f[i-1] + f[i-2];  // direct formula likh diya
        }

        return f[n];
    }
};
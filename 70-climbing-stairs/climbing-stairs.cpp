class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) return n;   // base cases
        int prev2 = 1, prev1 = 2; 
        int cur;
        for (int i = 3; i <= n; i++) {
            cur = prev1 + prev2;   // recurrence relation
            prev2 = prev1;
            prev1 = cur;
        }
        return prev1;
    }
};
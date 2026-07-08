class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) 
    {
        int n= nums.size();
        vector<vector<long>> dp(n+1, vector<long>(2,0)); //even= 0, odd= 1
        for(int i = 1; i<n+1; i++)
        {
            //even, even=odd-even
            dp[i][0]= max(dp[i-1][1]-nums[i-1],dp[i-1][0]);
            //odd, odd= odd+even
            dp[i][1]= max(dp[i-1][0]+nums[i-1],dp[i-1][1]);
        }
        return max(dp[n][0], dp[n][1]);
    }
};
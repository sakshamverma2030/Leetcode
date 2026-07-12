class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) 
   {
        int n = nums.size();
        sort(begin(nums), end(nums));
        vector<int>prev_idx(n,-1);

        vector<int> dp(n, 1);
        int last_chosen_idx = 0;
        int maxLIS = 1;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] % nums[j] == 0 && dp[i]<dp[j]+1)   
                {
                    dp[i]=dp[j]+1;
                    prev_idx[i]=j;
                  
                }
                if(dp[i]>maxLIS)
                {
                    maxLIS= dp[i];
                    last_chosen_idx=i;
                }
            }
        }
        vector<int>result;  
        while( last_chosen_idx!=-1)
        {
            result.push_back(nums[ last_chosen_idx]);
            last_chosen_idx =prev_idx[ last_chosen_idx];
        } 
        return result;
    }
};
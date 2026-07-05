class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int ans=0;
        for(auto &a:accounts) ans=max(ans,accumulate(a.begin(),a.end(),0));
        return ans;
    }
};

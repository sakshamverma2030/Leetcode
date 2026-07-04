class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans=0;
        for(int x:nums){
            int digits = to_string(x).size();
            if(digits % 2 == 0) ans++;
        }
        return ans;
    }
};

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> count;
        for(int i = 0; i <= n - k; i++) {
            unordered_set<int> seen; 
            for(int j = i; j < i + k; j++) {
                seen.insert(nums[j]);
            }
            for(int x : seen) {
                count[x]++;
            }
        }

        
        int ans = -1;
        for(auto &p : count) {
            if(p.second == 1) {
                ans = max(ans, p.first);
            }
        }
        return ans;
    }
};

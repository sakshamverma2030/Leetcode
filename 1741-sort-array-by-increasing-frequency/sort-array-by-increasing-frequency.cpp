class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> freq;
        for(int x : nums) freq[x]++;
        
        sort(nums.begin(), nums.end(), [&](int a, int b) {
            if(freq[a] == freq[b]) return a > b; // same freq → larger value first
            return freq[a] < freq[b];            // smaller freq first
        });
        
        return nums;
    }
};

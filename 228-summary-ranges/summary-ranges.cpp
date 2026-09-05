class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        int n = nums.size();
        if(n == 0) return res;

        int start = 0;
        while(start < n) {
            int end = start;
            while(end + 1 < n && nums[end+1] == nums[end] + 1) {
                end++;
            }

            if(start == end) {
                res.push_back(to_string(nums[start]));
            } else {
                res.push_back(to_string(nums[start]) + "->" + to_string(nums[end]));
            }

            start = end + 1;
        }
        return res;
    }
};

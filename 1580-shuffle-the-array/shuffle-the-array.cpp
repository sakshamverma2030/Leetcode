class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> result;
        result.reserve(2 * n); 
        
        for (int i = 0; i < n; i++) {
            result.push_back(nums[i]);     // x_i
            result.push_back(nums[i + n]); // y_i
        }
        return result;
    }
};

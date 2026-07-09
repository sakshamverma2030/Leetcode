class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first = INT_MAX;   // sabse chhota number
        int second = INT_MAX;  // second chhota number

        for (int num : nums) {
            if (num <= first) {
                first = num;   // update smallest
            } else if (num <= second) {
                second = num;  // update second smallest
            } else {
                return true;   // third number mil gaya
            }
        }
        return false;
    }
};

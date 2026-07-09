class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first = INT_MAX;   // sabse chhota number
        int second = INT_MAX;  // second chhota number

        for(int num : nums) {
            if(num <= first) {
                first = num;   // update smallest
            } else if(num <= second) {
                second = num;  // update second smallest
            } else {
                // agar koi number second se bada mil gaya
                return true;   // triplet exists
            }
        }
        return false;
    }
};

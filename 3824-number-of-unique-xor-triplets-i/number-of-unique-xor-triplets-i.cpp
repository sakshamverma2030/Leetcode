class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return n;
        
        // __builtin_clz gives leading zeros, bit length = 32 - clz
        int bit_length = 32 - __builtin_clz(n);
        return 1 << bit_length;
    }
};
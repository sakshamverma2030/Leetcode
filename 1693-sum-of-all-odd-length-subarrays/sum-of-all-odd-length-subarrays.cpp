class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n = arr.size();
        int total = 0;
        for(int i = 0; i < n; i++) {
            int left = i + 1;        // choices on left side
            int right = n - i;       // choices on right side
            int totalSubarrays = left * right;
            int oddSubarrays = (totalSubarrays + 1) / 2; // only odd length
            total += arr[i] * oddSubarrays;
        }
        return total;
    }
};

class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        
        // Find indices of min and max elements
        int minIndex = min_element(nums.begin(), nums.end()) - nums.begin();
        int maxIndex = max_element(nums.begin(), nums.end()) - nums.begin();
        
        // Ensure minIndex < maxIndex for easier handling
        if (minIndex > maxIndex) swap(minIndex, maxIndex);
        
        // Strategy 1: Remove both from front
        int front = max(minIndex, maxIndex) + 1;
        
        // Strategy 2: Remove both from back
        int back = n - min(minIndex, maxIndex);
        
        // Strategy 3: One from front, one from back
        int mixed = (minIndex + 1) + (n - maxIndex);
        
        return min({front, back, mixed});
    }
};

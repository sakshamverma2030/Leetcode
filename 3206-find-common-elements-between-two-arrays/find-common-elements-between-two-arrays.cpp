class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1(nums1.begin(), nums1.end());
        unordered_set<int> s2(nums2.begin(), nums2.end());
        
        int answer1 = 0, answer2 = 0;
        
        for(int x : nums1) {
            if(s2.count(x)) answer1++;
        }
        for(int x : nums2) {
            if(s1.count(x)) answer2++;
        }
        
        return {answer1, answer2};
    }
};

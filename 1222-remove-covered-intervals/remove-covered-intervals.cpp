class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        // Step 1: sort by start asc, end desc
        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b) {
            if (a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });
        
        int count = 0;
        int max_end = 0;
        
        // Step 2: greedy scan
        for (auto &interval : intervals) {
            if (interval[1] > max_end) {
                count++;
                max_end = interval[1];
            }
            // else covered → skip
        }
        return count;
    }
};

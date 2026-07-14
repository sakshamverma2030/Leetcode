class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<pair<int,int>> starts; // {start, index}
        
        for(int i=0; i<n; i++) {
            starts.push_back({intervals[i][0], i});
        }
        
        sort(starts.begin(), starts.end()); // sort by start
        
        vector<int> ans(n, -1);
        
        for(int i=0; i<n; i++) {
            int target = intervals[i][1]; // end of current interval
            
            // binary search in starts
            int l=0, r=n-1, pos=-1;
            while(l <= r) {
                int mid = l + (r-l)/2;
                if(starts[mid].first >= target) {
                    pos = starts[mid].second;
                    r = mid-1; // try to find smaller start
                } else {
                    l = mid+1;
                }
            }
            ans[i] = pos;
        }
        return ans;
    }
};

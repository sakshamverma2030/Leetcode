class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<pair<int,int>> arr;
        for(int i=0;i<n;i++) arr.push_back({nums[i], i});
        
        sort(arr.begin(), arr.end()); // sort by value
        
        vector<int> res(n);
        int start = 0;
        while(start < n) {
            int end = start;
            // expand group while consecutive values differ <= limit
            while(end+1 < n && arr[end+1].first - arr[end].first <= limit) {
                end++;
            }
            
            // collect indices and values of this group
            vector<int> indices, values;
            for(int i=start;i<=end;i++) {
                indices.push_back(arr[i].second);
                values.push_back(arr[i].first);
            }
            
            sort(indices.begin(), indices.end());
            sort(values.begin(), values.end());
            
            // assign sorted values to sorted indices
            for(int i=0;i<indices.size();i++) {
                res[indices[i]] = values[i];
            }
            
            start = end+1;
        }
        
        return res;
    }
};

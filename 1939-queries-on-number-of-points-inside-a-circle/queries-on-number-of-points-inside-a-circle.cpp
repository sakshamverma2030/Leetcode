class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int> ans;
        for(auto &q : queries) {
            int cx = q[0], cy = q[1], r = q[2];
            int count = 0;
            for(auto &p : points) {
                int dx = p[0] - cx;
                int dy = p[1] - cy;
                if(dx*dx + dy*dy <= r*r) {
                    count++;
                }
            }
            ans.push_back(count);
        }
        return ans;
    }
};

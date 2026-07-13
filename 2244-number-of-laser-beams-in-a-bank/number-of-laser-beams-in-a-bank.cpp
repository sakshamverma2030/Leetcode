class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prev = 0, ans = 0;
        for(string &row : bank) {
            int devices = count(row.begin(), row.end(), '1');
            if(devices > 0) {
                ans += prev * devices;
                prev = devices;
            }
        }
        return ans;
    }
};

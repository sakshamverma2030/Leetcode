class Solution {
public:
    int earliestTime(vector<vector<int>>& tasks) {
        int ans = INT_MAX; // start with maximum possible
        for(int i = 0; i < tasks.size(); i++) {
            int start = tasks[i][0];     // si
            int duration = tasks[i][1];  // ti
            int finish = start + duration; // finish time
            ans = min(ans, finish);      // keep track of earliest finish
        }
        return ans;
    }
};
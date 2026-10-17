class Solution {
public:
    int digitSum(int x) {
        int sum = 0;
        while (x) {
            sum += x % 10;
            x /= 10;
        }
        return sum;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        vector<int> sorted = nums;

        sort(sorted.begin(), sorted.end(),
             [&](int a, int b) {
                 int sa = digitSum(a);
                 int sb = digitSum(b);

                 if (sa != sb) return sa < sb;
                 return a < b;
             });

        unordered_map<int, int> pos;

        for (int i = 0; i < n; i++) {
            pos[sorted[i]] = i;
        }

        vector<bool> vis(n, false);
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (vis[i] || pos[nums[i]] == i) continue;

            int len = 0;
            int cur = i;

            while (!vis[cur]) {
                vis[cur] = true;
                cur = pos[nums[cur]];
                len++;
            }

            ans += len - 1;
        }

        return ans;
    }
};

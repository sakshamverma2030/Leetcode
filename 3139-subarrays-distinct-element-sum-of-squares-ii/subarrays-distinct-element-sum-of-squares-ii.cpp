class Solution {
public:
    static constexpr long long MOD = 1000000007LL;

    struct Node {
        long long sum = 0;   // sum of distinct counts
        long long sq = 0;    // sum of squares
        long long lazy = 0;
    };

    vector<Node> seg;

    void apply(int idx, int l, int r, long long val) {
        long long len = r - l + 1;

        seg[idx].sq =
            (seg[idx].sq +
             (2LL * val % MOD * seg[idx].sum) % MOD +
             (len % MOD * val % MOD * val) % MOD) % MOD;

        seg[idx].sum =
            (seg[idx].sum + (len % MOD * val) % MOD) % MOD;

        seg[idx].lazy =
            (seg[idx].lazy + val) % MOD;
    }

    void push(int idx, int l, int r) {
        if (seg[idx].lazy == 0 || l == r)
            return;

        int mid = (l + r) >> 1;
        long long v = seg[idx].lazy;

        apply(idx << 1, l, mid, v);
        apply(idx << 1 | 1, mid + 1, r, v);

        seg[idx].lazy = 0;
    }

    void update(int idx, int l, int r,
                int ql, int qr, long long val) {

        if (ql > r || qr < l)
            return;

        if (ql <= l && r <= qr) {
            apply(idx, l, r, val);
            return;
        }

        push(idx, l, r);

        int mid = (l + r) >> 1;

        update(idx << 1, l, mid, ql, qr, val);
        update(idx << 1 | 1, mid + 1, r, ql, qr, val);

        seg[idx].sum =
            (seg[idx << 1].sum + seg[idx << 1 | 1].sum) % MOD;

        seg[idx].sq =
            (seg[idx << 1].sq + seg[idx << 1 | 1].sq) % MOD;
    }

    int sumCounts(vector<int>& nums) {
        int n = nums.size();

        seg.assign(4 * n + 5, Node());

        unordered_map<int, int> last;

        long long ans = 0;

        for (int i = 0; i < n; i++) {
            int prev = -1;

            if (last.count(nums[i]))
                prev = last[nums[i]];

            // increase distinct count for all starts
            // in [prev+1, i]
            update(1, 0, n - 1, prev + 1, i, 1);

            ans = (ans + seg[1].sq) % MOD;

            last[nums[i]] = i;
        }

        return (int)ans;
    }
};
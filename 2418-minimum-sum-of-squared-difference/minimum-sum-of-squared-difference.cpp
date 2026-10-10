class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2,
                               int k1, int k2) {

        long long k = (long long)k1 + k2;

        vector<long long> diff;
        long long total = 0;
        int mx = 0;

        for (int i = 0; i < nums1.size(); i++) {
            long long d = abs(nums1[i] - nums2[i]);
            diff.push_back(d);
            total += d;
            mx = max(mx, (int)d);
        }

        if (k >= total) return 0;

        long long lo = 0, hi = mx;

        while (lo < hi) {
            long long mid = (lo + hi) / 2;

            long long need = 0;
            for (long long d : diff) {
                if (d > mid)
                    need += d - mid;
            }

            if (need <= k)
                hi = mid;
            else
                lo = mid + 1;
        }

        long long t = lo;

        long long used = 0;
        vector<long long> a;

        for (long long d : diff) {
            if (d > t) {
                used += d - t;
                a.push_back(t);
            } else {
                a.push_back(d);
            }
        }

        long long rem = k - used;

        for (long long &d : a) {
            if (rem == 0) break;

            if (d == t && d > 0) {
                d--;
                rem--;
            }
        }

        long long ans = 0;

        for (long long d : a) {
            ans += d * d;
        }

        return ans;
    }
};
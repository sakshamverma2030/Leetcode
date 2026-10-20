class Solution {
public:
    bool isRotation(const vector<int>& B, const vector<int>& T) {
        int k = B.size();

        vector<int> lps(k, 0);

        for (int i = 1, j = 0; i < k; ) {
            if (T[i] == T[j]) {
                lps[i++] = ++j;
            } else if (j) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }

        int j = 0;

        for (int i = 0; i < 2 * k - 1; i++) {
            int x = B[i % k];

            while (j > 0 && x != T[j]) {
                j = lps[j - 1];
            }

            if (x == T[j]) {
                j++;
            }

            if (j == k) {
                return true;
            }
        }

        return false;
    }

    long long sortableIntegers(vector<int>& nums) {
        int n = nums.size();

        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());

        vector<int> divisors;

        for (int d = 1; d * d <= n; d++) {
            if (n % d == 0) {
                divisors.push_back(d);

                if (d * d != n) {
                    divisors.push_back(n / d);
                }
            }
        }

        long long ans = 0;

        for (int k : divisors) {
            bool ok = true;

            for (int start = 0; start < n && ok; start += k) {
                vector<int> B(
                    nums.begin() + start,
                    nums.begin() + start + k
                );

                vector<int> T(
                    sortedNums.begin() + start,
                    sortedNums.begin() + start + k
                );

                if (!isRotation(B, T)) {
                    ok = false;
                }
            }

            if (ok) {
                ans += k;
            }
        }

        return ans;
    }
};
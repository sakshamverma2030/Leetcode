#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    int factor2(int d) {
        if (d == 2 || d == 6) return 1;
        if (d == 4) return 2;
        if (d == 8) return 3;
        return 0;
    }

    int factor3(int d) {
        if (d == 3 || d == 6) return 1;
        if (d == 9) return 2;
        return 0;
    }

    int factor5(int d) { return d == 5 ? 1 : 0; }
    int factor7(int d) { return d == 7 ? 1 : 0; }

    // Calculates the minimum number of digits needed to satisfy (r2, r3, r5, r7)
    int min_suffix_len(long long r2, long long r3, long long r5, long long r7) {
        r2 = max(0LL, r2);
        r3 = max(0LL, r3);
        r5 = max(0LL, r5);
        r7 = max(0LL, r7);

        long long c9 = r3 / 2;
        long long rem3 = r3 % 2;
        long long c8 = r2 / 3;
        long long rem2 = r2 % 3;

        int extra = 0;
        if (rem3 == 0 && rem2 == 0) extra = 0;
        else if (rem3 == 0 && rem2 == 1) extra = 1; // digit 2
        else if (rem3 == 0 && rem2 == 2) extra = 1; // digit 4
        else if (rem3 == 1 && rem2 == 0) extra = 1; // digit 3
        else if (rem3 == 1 && rem2 == 1) extra = 1; // digit 6
        else if (rem3 == 1 && rem2 == 2) extra = 2; // digits (3, 4) or (2, 6)

        return r7 + r5 + c9 + c8 + extra;
    }

    // Greedily constructs the lexicographically smallest string of given length
    string fill_suffix(int len, long long r2, long long r3, long long r5, long long r7) {
        string res = "";
        for (int pos = 0; pos < len; ++pos) {
            int rem_len = len - 1 - pos;
            for (int d = 1; d <= 9; ++d) {
                long long nr2 = r2 - factor2(d);
                long long nr3 = r3 - factor3(d);
                long long nr5 = r5 - factor5(d);
                long long nr7 = r7 - factor7(d);

                if (min_suffix_len(nr2, nr3, nr5, nr7) <= rem_len) {
                    res += to_string(d);
                    r2 = nr2;
                    r3 = nr3;
                    r5 = nr5;
                    r7 = nr7;
                    break;
                }
            }
        }
        return res;
    }

public:
    string smallestNumber(string num, long long t) {
        // Step 1: Prime factorization of t
        long long c2 = 0, c3 = 0, c5 = 0, c7 = 0;
        long long temp_t = t;
        while (temp_t % 2 == 0) { c2++; temp_t /= 2; }
        while (temp_t % 3 == 0) { c3++; temp_t /= 3; }
        while (temp_t % 5 == 0) { c5++; temp_t /= 5; }
        while (temp_t % 7 == 0) { c7++; temp_t /= 7; }
        
        // If t has any prime factors > 7, it's impossible
        if (temp_t > 1) return "-1";

        int n = num.length();
        int zero_idx = n;
        for (int i = 0; i < n; ++i) {
            if (num[i] == '0') {
                zero_idx = i;
                break;
            }
        }

        // Step 2: Check if num itself works
        if (zero_idx == n) {
            long long p2 = 0, p3 = 0, p5 = 0, p7 = 0;
            for (char ch : num) {
                int d = ch - '0';
                p2 += factor2(d);
                p3 += factor3(d);
                p5 += factor5(d);
                p7 += factor7(d);
            }
            if (p2 >= c2 && p3 >= c3 && p5 >= c5 && p7 >= c7) {
                return num;
            }
        }

        // Step 3: Prefix matching for length n
        vector<long long> pref2(n + 1, 0), pref3(n + 1, 0), pref5(n + 1, 0), pref7(n + 1, 0);
        for (int i = 0; i < zero_idx; ++i) {
            int d = num[i] - '0';
            pref2[i + 1] = pref2[i] + factor2(d);
            pref3[i + 1] = pref3[i] + factor3(d);
            pref5[i + 1] = pref5[i] + factor5(d);
            pref7[i + 1] = pref7[i] + factor7(d);
        }

        for (int i = min(n - 1, zero_idx); i >= 0; --i) {
            long long p2 = pref2[i];
            long long p3 = pref3[i];
            long long p5 = pref5[i];
            long long p7 = pref7[i];

            int start_d = num[i] - '0' + 1;
            for (int d = start_d; d <= 9; ++d) {
                long long r2 = c2 - p2 - factor2(d);
                long long r3 = c3 - p3 - factor3(d);
                long long r5 = c5 - p5 - factor5(d);
                long long r7 = c7 - p7 - factor7(d);

                if (min_suffix_len(r2, r3, r5, r7) <= n - 1 - i) {
                    string prefix = num.substr(0, i) + to_string(d);
                    string suffix = fill_suffix(n - 1 - i, r2, r3, r5, r7);
                    return prefix + suffix;
                }
            }
        }

        // Step 4: If no solution of length n, expand to length n + 1
        int target_len = max((long long)n + 1, (long long)min_suffix_len(c2, c3, c5, c7));
        return fill_suffix(target_len, c2, c3, c5, c7);
    }
};
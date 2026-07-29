#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    // Computes nCr capped at cap
    long long comb(int n, int r, long long cap) {
        if (r < 0 || r > n) return 0;
        if (r == 0 || r == n) return 1;
        if (r > n - r) r = n - r;
        
        long long res = 1;
        for (int i = 1; i <= r; ++i) {
            res = res * (n - i + 1) / i;
            if (res > cap) return cap;
        }
        return res;
    }

    // Computes total permutations of remaining character counts capped at cap
    long long getWays(const vector<int>& counts, int totalLen, long long cap) {
        long long ways = 1;
        int rem = totalLen;
        for (int c : counts) {
            if (c == 0) continue;
            ways *= comb(rem, c, cap);
            if (ways > cap) return cap;
            rem -= c;
        }
        return ways;
    }

public:
    string smallestPalindrome(string s, int k) {
        int n = s.length();
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }

        // Half character frequencies
        vector<int> halfFreq(26, 0);
        char midChar = 0;
        for (int i = 0; i < 26; ++i) {
            halfFreq[i] = freq[i] / 2;
            if (freq[i] % 2 != 0) {
                midChar = 'a' + i;
            }
        }

        int m = n / 2;
        long long targetK = k;
        
        // Check if total possible permutations is at least k
        long long totalWays = getWays(halfFreq, m, targetK);
        if (totalWays < targetK) {
            return "";
        }

        string leftHalf = "";
        leftHalf.reserve(m);

        for (int i = 0; i < m; ++i) {
            if (targetK == 1) {
                // Fill the remaining characters in sorted order
                for (int c = 0; c < 26; ++c) {
                    while (halfFreq[c] > 0) {
                        leftHalf += (char)('a' + c);
                        halfFreq[c]--;
                    }
                }
                break;
            }

            int remainingLen = m - 1 - i;
            for (int c = 0; c < 26; ++c) {
                if (halfFreq[c] == 0) continue;

                halfFreq[c]--;
                long long ways = getWays(halfFreq, remainingLen, targetK);

                if (targetK <= ways) {
                    leftHalf += (char)('a' + c);
                    break; // Character placed
                } else {
                    targetK -= ways;
                    halfFreq[c]++; // Backtrack and try next character
                }
            }
        }

        // Reconstruct full palindrome
        string rightHalf = leftHalf;
        reverse(rightHalf.begin(), rightHalf.end());

        if (n % 2 != 0) {
            return leftHalf + midChar + rightHalf;
        } else {
            return leftHalf + rightHalf;
        }
    }
};
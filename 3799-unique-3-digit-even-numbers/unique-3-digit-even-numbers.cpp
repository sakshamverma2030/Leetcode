class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        vector<int> freq(10, 0);
        for (int d : digits) freq[d]++;

        int count = 0;

        // Iterate all 3-digit numbers
        for (int num = 100; num <= 999; num++) {
            if (num % 2 != 0) continue; // must be even

            int x = num;
            vector<int> need(10, 0);
            for (int i = 0; i < 3; i++) {
                int d = x % 10;
                need[d]++;
                x /= 10;
            }

            bool ok = true;
            for (int d = 0; d < 10; d++) {
                if (need[d] > freq[d]) {
                    ok = false;
                    break;
                }
            }

            if (ok) count++;
        }

        return count;
    }
};

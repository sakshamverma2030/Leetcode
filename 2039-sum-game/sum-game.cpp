class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int half = n / 2;
        
        int sumLeft = 0, sumRight = 0;
        int qLeft = 0, qRight = 0;
        
        // Calculate sums and '?' counts
        for (int i = 0; i < half; i++) {
            if (num[i] == '?') qLeft++;
            else sumLeft += num[i] - '0';
        }
        for (int i = half; i < n; i++) {
            if (num[i] == '?') qRight++;
            else sumRight += num[i] - '0';
        }
        
        // Case 1: odd number of '?'
        if ((qLeft + qRight) % 2 == 1) return true;
        
        // Case 2: check balance condition
        return (sumLeft - sumRight) != (qRight - qLeft) * 9 / 2;
    }
};

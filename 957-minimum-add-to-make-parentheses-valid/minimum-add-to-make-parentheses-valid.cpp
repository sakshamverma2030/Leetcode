class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0;
        int moves = 0;

        for (char ch : s) {
            if (ch == '(') {
                open++;
            } else {
                if (open > 0) {
                    open--;
                } else {
                    moves++;
                }
            }
        }

        return moves + open;
    }
};
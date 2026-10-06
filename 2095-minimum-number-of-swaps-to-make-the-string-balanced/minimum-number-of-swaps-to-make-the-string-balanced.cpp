class Solution {
public:
    int minSwaps(string s) {
        int open = 0;
        int unmatchedClose = 0;

        for(char c : s) {
            if(c == '[') {
                open++;
            } else {
                if(open > 0)
                    open--;
                else
                    unmatchedClose++;
            }
        }

        return (unmatchedClose + 1) / 2;
    }
};
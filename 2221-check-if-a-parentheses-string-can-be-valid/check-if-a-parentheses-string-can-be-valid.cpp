class Solution {
public:
    bool canBeValid(string s, string locked) {

        int n = s.size();

        if (n & 1)
            return false;

        int open = 0, free = 0;

        for (int i = 0; i < n; i++) {

            if (locked[i] == '0')
                free++;

            else if (s[i] == '(')
                open++;

            else {

                if (open > 0)
                    open--;

                else if (free > 0)
                    free--;

                else
                    return false;
            }
        }

        int close = 0;
        free = 0;

        for (int i = n - 1; i >= 0; i--) {

            if (locked[i] == '0')
                free++;

            else if (s[i] == ')')
                close++;

            else {

                if (close > 0)
                    close--;

                else if (free > 0)
                    free--;

                else
                    return false;
            }
        }

        return true;
    }
};
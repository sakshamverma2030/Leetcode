class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (sum > 9 * num) return "";

        if (num == 1) {
            return (sum <= 9) ? to_string(sum) : "";
        }

        int nines = sum / 9;
        int rem = sum % 9;

        int zeros = num - nines - (rem > 0 ? 1 : 0);

        string ans;

        ans.append(nines, '9');

        if (rem > 0)
            ans.push_back('0' + rem);

        ans.append(zeros, '0');

        return ans;
    }
};
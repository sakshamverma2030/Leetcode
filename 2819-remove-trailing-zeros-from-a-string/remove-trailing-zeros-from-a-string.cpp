class Solution {
public:
    string removeTrailingZeros(string num) {
        int i = num.size() - 1;

        // peeche se traverse karo jab tak '0' milta hai
        while (i >= 0 && num[i] == '0') {
            i--;
        }

        // substring lo jo last non-zero tak hai
        return num.substr(0, i + 1);
    }
};

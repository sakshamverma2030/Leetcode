class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for (int num : nums) {
            vector<int> temp;
            while (num > 0) {
                temp.push_back(num % 10); // extract last digit
                num /= 10;
            }
            reverse(temp.begin(), temp.end()); // maintain correct order
            ans.insert(ans.end(), temp.begin(), temp.end());
        }
        return ans;
    }
};

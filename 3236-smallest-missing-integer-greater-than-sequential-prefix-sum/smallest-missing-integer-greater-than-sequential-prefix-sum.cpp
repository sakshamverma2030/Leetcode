class Solution {
public:
    int missingInteger(vector<int>& nums) {
        // Step 1: Longest sequential prefix find karo
        int i = 0;
        while (i + 1 < nums.size() && nums[i+1] == nums[i] + 1) {
            i++;
        }

        // Step 2: Prefix sum nikal lo
        int sum = 0;
        for (int j = 0; j <= i; j++) {
            sum += nums[j];
        }

        // Step 3: Array ke elements ko set me daal lo
        unordered_set<int> st(nums.begin(), nums.end());

        // Step 4: sum se start karke pehla missing number dhoondo
        while (st.count(sum)) {
            sum++;
        }
        return sum;
    }
};

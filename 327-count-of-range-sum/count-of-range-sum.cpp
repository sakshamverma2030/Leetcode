class Solution {
public:
    long long mergeSort(vector<long long>& pre, int left, int right,
                        int lower, int upper) {
        if (left >= right) return 0;

        int mid = left + (right - left) / 2;

        long long count = 0;

        count += mergeSort(pre, left, mid, lower, upper);
        count += mergeSort(pre, mid + 1, right, lower, upper);

        int low = mid + 1;
        int high = mid + 1;

        for (int i = left; i <= mid; i++) {

            while (low <= right &&
                   pre[low] - pre[i] < lower)
                low++;

            while (high <= right &&
                   pre[high] - pre[i] <= upper)
                high++;

            count += (high - low);
        }

        vector<long long> temp;
        int i = left;
        int j = mid + 1;

        while (i <= mid && j <= right) {
            if (pre[i] <= pre[j])
                temp.push_back(pre[i++]);
            else
                temp.push_back(pre[j++]);
        }

        while (i <= mid) temp.push_back(pre[i++]);
        while (j <= right) temp.push_back(pre[j++]);

        for (int k = 0; k < temp.size(); k++)
            pre[left + k] = temp[k];

        return count;
    }

    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();

        vector<long long> pre(n + 1, 0);

        for (int i = 0; i < n; i++)
            pre[i + 1] = pre[i] + nums[i];

        return (int)mergeSort(pre, 0, n, lower, upper);
    }
};
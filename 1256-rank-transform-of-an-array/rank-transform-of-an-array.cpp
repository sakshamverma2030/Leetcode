class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        // Step 1: copy + sort
        vector<int> sortedArr = arr;
        sort(sortedArr.begin(), sortedArr.end());

        // Step 2: assign ranks to unique elements
        unordered_map<int,int> rank;
        int r = 1;
        for (int x : sortedArr) {
            if (rank.find(x) == rank.end()) {
                rank[x] = r++;
            }
        }

        // Step 3: build result using rank map
        vector<int> result;
        result.reserve(arr.size());
        for (int x : arr) {
            result.push_back(rank[x]);
        }

        return result;
    }
};

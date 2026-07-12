class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        // Step 1: copy + sort
        vector<int> sortedArr = arr;
        sort(sortedArr.begin(), sortedArr.end());

        // Step 2: assign ranks to unique elements
        unordered_map<int,int> rank;
        int r = 1;

        // loop khol ke likha hai
        for (int i = 0; i < sortedArr.size(); i++) {
            int x = sortedArr[i];
            if (rank.find(x) == rank.end()) {
                rank[x] = r;
                r = r + 1;
            }
        }

        // Step 3: build result using rank map
        vector<int> result;
        result.reserve(arr.size());

        // loop khol ke likha hai
        for (int i = 0; i < arr.size(); i++) {
            int x = arr[i];
            int rx = rank[x];
            result.push_back(rx);
        }

        return result;
    }
};

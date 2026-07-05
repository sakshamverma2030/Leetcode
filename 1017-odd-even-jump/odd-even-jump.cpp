#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    int oddEvenJumps(vector<int>& arr) {
        int n = arr.size();
        vector<int> nextHigher(n, -1), nextLower(n, -1);

        // indices sorted by values (for odd jumps)
        vector<int> idx(n);
        for (int i = 0; i < n; i++) idx[i] = i;

        // Odd jump: sort by value ascending, then index ascending
        sort(idx.begin(), idx.end(), [&](int a, int b) {
            if (arr[a] == arr[b]) return a < b;
            return arr[a] < arr[b];
        });
        buildNext(idx, nextHigher);

        // Even jump: sort by value descending, then index ascending
        sort(idx.begin(), idx.end(), [&](int a, int b) {
            if (arr[a] == arr[b]) return a < b;
            return arr[a] > arr[b];
        });
        buildNext(idx, nextLower);

        // DP arrays
        vector<bool> odd(n, false), even(n, false);
        odd[n-1] = even[n-1] = true;

        for (int i = n-2; i >= 0; i--) {
            if (nextHigher[i] != -1) odd[i] = even[nextHigher[i]];
            if (nextLower[i] != -1) even[i] = odd[nextLower[i]];
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (odd[i]) ans++;
        }
        return ans;
    }

private:
    void buildNext(vector<int>& idx, vector<int>& next) {
        stack<int> st;
        for (int i : idx) {
            while (!st.empty() && i > st.top()) {
                next[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
    }
};



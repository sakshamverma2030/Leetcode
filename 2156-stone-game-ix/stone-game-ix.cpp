#include <vector>
#include <cmath>
#include <cstdlib>

using namespace std;

class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int c0 = 0, c1 = 0, c2 = 0;
        
        for (int stone : stones) {
            int rem = stone % 3;
            if (rem == 0) c0++;
            else if (rem == 1) c1++;
            else c2++;
        }

        if (c0 % 2 == 0) {
            return c1 >= 1 && c2 >= 1;
        } else {
            return abs(c1 - c2) >= 3;
        }
    }
};
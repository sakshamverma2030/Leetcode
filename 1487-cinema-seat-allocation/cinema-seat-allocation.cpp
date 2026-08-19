#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, unordered_set<int>> reserved;
        
        // Store reserved seats per row
        for (auto &seat : reservedSeats) {
            reserved[seat[0]].insert(seat[1]);
        }
        
        int result = 0;
        
        // Process rows with reservations
        for (auto &row : reserved) {
            auto &seats = row.second;
            
            bool left   = !(seats.count(2) || seats.count(3) || seats.count(4) || seats.count(5));
            bool middle = !(seats.count(4) || seats.count(5) || seats.count(6) || seats.count(7));
            bool right  = !(seats.count(6) || seats.count(7) || seats.count(8) || seats.count(9));
            
            if (left && right) result += 2;
            else if (left || middle || right) result += 1;
        }
        
        // Rows without reservations → 2 groups each
        result += (n - reserved.size()) * 2;
        
        return result;
    }
};

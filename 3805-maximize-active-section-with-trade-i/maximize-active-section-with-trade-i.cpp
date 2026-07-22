#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    int maxActiveSectionsAfterTrade(std::string s) {
        int total_ones = 0;
        std::vector<int> zero_lengths;
        
        int cur_zeros = 0;
        for (char c : s) {
            if (c == '1') {
                total_ones++;
                if (cur_zeros > 0) {
                    zero_lengths.push_back(cur_zeros);
                    cur_zeros = 0;
                }
            } else {
                cur_zeros++;
            }
        }
        if (cur_zeros > 0) {
            zero_lengths.push_back(cur_zeros);
        }
        
        int max_trade_gain = 0;
        for (size_t i = 0; i + 1 < zero_lengths.size(); ++i) {
            max_trade_gain = std::max(max_trade_gain, zero_lengths[i] + zero_lengths[i + 1]);
        }
        
        return total_ones + max_trade_gain;
    }
};
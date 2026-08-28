#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.length();
        int m = n / 2;
        
        vector<int> counts(26, 0);
        for (char c : s) {
            counts[c - 'a']++;
        }
        
        // Check validity: at most one odd-frequency character
        int odd_count = 0;
        char mid_char = '\0';
        for (int i = 0; i < 26; ++i) {
            if (counts[i] % 2 != 0) {
                odd_count++;
                mid_char = 'a' + i;
            }
        }
        if (odd_count > 1) {
            return "";
        }
        
        // Frequency of characters for the left half of the palindrome
        vector<int> half_counts(26, 0);
        for (int i = 0; i < 26; ++i) {
            half_counts[i] = counts[i] / 2;
        }
        
        // Helper lambda to assemble the full palindrome
        auto build_palindrome = [&](const string& first_half) -> string {
            string full = first_half;
            if (n % 2 != 0) {
                full.push_back(mid_char);
            }
            string right_half = first_half;
            reverse(right_half.begin(), right_half.end());
            full += right_half;
            return full;
        };
        
        // Try to match a prefix of target of length i (from m down to 0)
        for (int i = m; i >= 0; --i) {
            vector<int> temp_counts = half_counts;
            bool possible = true;
            
            // 1. Try to match prefix target[0...i-1]
            for (int j = 0; j < i; ++j) {
                int char_idx = target[j] - 'a';
                if (temp_counts[char_idx] > 0) {
                    temp_counts[char_idx]--;
                } else {
                    possible = false;
                    break;
                }
            }
            
            if (!possible) continue;
            
            string prefix = target.substr(0, i);
            
            // Case 1: Exact prefix match of length m
            if (i == m) {
                string cand = build_palindrome(prefix);
                if (cand > target) {
                    return cand;
                }
                continue;
            }
            
            // Case 2: Match prefix up to i-1, pick a strictly larger character at index i
            int target_char_idx = target[i] - 'a';
            for (int next_char_idx = target_char_idx + 1; next_char_idx < 26; ++next_char_idx) {
                if (temp_counts[next_char_idx] > 0) {
                    vector<int> curr_counts = temp_counts;
                    curr_counts[next_char_idx]--;
                    
                    string cand_first_half = prefix;
                    cand_first_half.push_back('a' + next_char_idx);
                    
                    // Append remaining characters in ascending order
                    for (int c = 0; c < 26; ++c) {
                        cand_first_half.append(curr_counts[c], 'a' + c);
                    }
                    
                    string cand = build_palindrome(cand_first_half);
                    if (cand > target) {
                        return cand;
                    }
                }
            }
        }
        
        return "";
    }
};
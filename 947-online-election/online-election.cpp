#include <vector>
#include <unordered_map>
#include <algorithm>

class TopVotedCandidate {
private:
    vector<int> times;
    vector<int> leaders;

public:
    TopVotedCandidate(std::vector<int>& persons, std::vector<int>& times) : times(times) {
        int n = persons.size();
        leaders.resize(n);
        
        std::unordered_map<int, int> count;
        int lead = -1;
        int max_votes = 0;

        for (int i = 0; i < n; ++i) {
            int p = persons[i];
            count[p]++;
            
            
            if (count[p] >= max_votes) {
                max_votes = count[p];
                lead = p;
            }
            leaders[i] = lead;
        }
    }
    
    int q(int t) {
        
        auto it = std::upper_bound(times.begin(), times.end(), t);
        
        int idx = std::distance(times.begin(), it) - 1;
        return leaders[idx];
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */
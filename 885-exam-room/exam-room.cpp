#include <set>
#include <algorithm>

class ExamRoom {
private:
    int n;
    set<int> occupied;

public:
    ExamRoom(int n) : n(n) {}
    
    int seat() {
        if (occupied.empty()) {
            occupied.insert(0);
            return 0;
        }

        int max_dist = *occupied.begin(); 
        int seat_idx = 0;

        
        auto prev = occupied.begin();
        for (auto curr = std::next(occupied.begin()); curr != occupied.end(); ++curr) {
            int prev_seat = *prev;
            int curr_seat = *curr;
            int dist = (curr_seat - prev_seat) / 2;

            if (dist > max_dist) {
                max_dist = dist;
                seat_idx = prev_seat + dist;
            }
            prev = curr;
        }

        
        int last_dist = (n - 1) - *occupied.rbegin();
        if (last_dist > max_dist) {
            seat_idx = n - 1;
        }

        occupied.insert(seat_idx);
        return seat_idx;
    }
    
    void leave(int p) {
        occupied.erase(p);
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(n);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */
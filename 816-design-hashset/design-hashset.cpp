#include <vector>
#include <algorithm>

class MyHashSet {
private:
    static const int BASE = 1009;
    std::vector<int> table[BASE];

    int hash(int key) {
        return key % BASE;
    }

public:
    MyHashSet() {}

    void add(int key) {
        int idx = hash(key);
        for (int el : table[idx]) {
            if (el == key) return; 
        }
        table[idx].push_back(key);
    }

    void remove(int key) {
        int idx = hash(key);
        auto& bucket = table[idx];
        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if (*it == key) {
                bucket.erase(it);
                return;
            }
        }
    }

    bool contains(int key) {
        int idx = hash(key);
        for (int el : table[idx]) {
            if (el == key) return true;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
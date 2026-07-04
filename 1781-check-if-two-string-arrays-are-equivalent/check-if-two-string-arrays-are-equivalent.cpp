class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& w1, vector<string>& w2) {
        return accumulate(w1.begin(),w1.end(),string(""))==accumulate(w2.begin(),w2.end(),string(""));
    }
};

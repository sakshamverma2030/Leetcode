class Solution {
public:
    int maxDistinct(string s) {
        // ek set banate hain jo distinct characters store karega
        unordered_set<char> distinctChars(s.begin(), s.end());

        // answer = distinct characters ki count
        return distinctChars.size();
    }
};

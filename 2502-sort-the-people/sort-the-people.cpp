class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = names.size();
        vector<pair<int,string>> people;
        for(int i = 0; i < n; i++) {
            people.push_back({heights[i], names[i]});
        }
        sort(people.begin(), people.end(), [](auto &a, auto &b){
            return a.first > b.first; // descending by height
        });
        vector<string> ans;
        for(auto &p : people) {
            ans.push_back(p.second);
        }
        return ans;
    }
};

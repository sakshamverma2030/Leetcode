class Solution {
public:
    vector<string> braceExpansionII(string expression) {
        int i = 0;
        vector<string> res = parse(expression, i);
        
        sort(res.begin(), res.end());
        res.erase(unique(res.begin(), res.end()), res.end());
        
        return res;
    }
    
private:
    vector<string> parse(const string& expr, int& i) {
        vector<string> res;
        vector<string> cur_group = {""};
        
        while (i < expr.length() && expr[i] != '}') {
            if (expr[i] == ',') {
                res.insert(res.end(), cur_group.begin(), cur_group.end());
                cur_group = {""};
                i++;
            } else {
                vector<string> next_set;
                if (expr[i] == '{') {
                    i++;
                    next_set = parse(expr, i);
                    i++;
                } else {
                    next_set = {string(1, expr[i])};
                    i++;
                }
                
                vector<string> combined;
                for (const string& a : cur_group) {
                    for (const string& b : next_set) {
                        combined.push_back(a + b);
                    }
                }
                cur_group = move(combined);
            }
        }
        
        res.insert(res.end(), cur_group.begin(), cur_group.end());
        return res;
    }
};
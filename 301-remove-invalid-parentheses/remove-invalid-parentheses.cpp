class Solution {
public:
    bool isValid(string s) {
        int bal = 0;

        for(char c : s) {
            if(c == '(')
                bal++;
            else if(c == ')') {
                bal--;
                if(bal < 0)
                    return false;
            }
        }

        return bal == 0;
    }

    vector<string> removeInvalidParentheses(string s) {

        unordered_set<string> visited;
        queue<string> q;
        vector<string> ans;

        q.push(s);
        visited.insert(s);

        bool found = false;

        while(!q.empty()) {

            int sz = q.size();

            while(sz--) {

                string cur = q.front();
                q.pop();

                if(isValid(cur)) {
                    ans.push_back(cur);
                    found = true;
                }

                if(found)
                    continue;

                for(int i = 0; i < cur.size(); i++) {

                    if(cur[i] != '(' && cur[i] != ')')
                        continue;

                    string nxt =
                        cur.substr(0, i) +
                        cur.substr(i + 1);

                    if(!visited.count(nxt)) {
                        visited.insert(nxt);
                        q.push(nxt);
                    }
                }
            }

            if(found)
                break;
        }

        return ans;
    }
};
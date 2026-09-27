class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;

        for (char ch : s) {
            if (ch == ')') {
                string temp;

                while (!st.empty() && st.top() != '(') {
                    temp += st.top();
                    st.pop();
                }

                st.pop(); 

                for (char c : temp) {
                    st.push(c);
                }
            } else {
                st.push(ch);
            }
        }

        string ans;

        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;

        int n = s.size();
        int m = words.size();
        int wlen = words[0].size();

        int totalLen = m * wlen;

        if (n < totalLen) return ans;

        unordered_map<string, int> need;

        for (auto &w : words)
            need[w]++;

        for (int offset = 0; offset < wlen; offset++) {

            unordered_map<string, int> window;

            int left = offset;
            int count = 0;

            for (int right = offset;
                 right + wlen <= n;
                 right += wlen) {

                string word = s.substr(right, wlen);

                if (need.count(word)) {

                    window[word]++;
                    count++;

                    while (window[word] > need[word]) {

                        string leftWord =
                            s.substr(left, wlen);

                        window[leftWord]--;
                        left += wlen;
                        count--;
                    }

                    if (count == m) {

                        ans.push_back(left);

                        string leftWord =
                            s.substr(left, wlen);

                        window[leftWord]--;
                        left += wlen;
                        count--;
                    }

                } else {

                    window.clear();
                    count = 0;
                    left = right + wlen;
                }
            }
        }

        return ans;
    }
};
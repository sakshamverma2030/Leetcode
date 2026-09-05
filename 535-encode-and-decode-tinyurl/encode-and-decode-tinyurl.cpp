class Solution {
public:
    unordered_map<string,string> mp;
    int id = 0;

    string encode(string longUrl) {
        string shortUrl = "http://tinyurl.com/" + to_string(id++);
        mp[shortUrl] = longUrl;
        return shortUrl;
    }
    string decode(string shortUrl) {
        return mp[shortUrl];
    }
};

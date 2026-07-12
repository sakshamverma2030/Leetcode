class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int m = str1.length();  
        int n = str2.length();   

        vector<vector<int>> dp(m+1, vector<int>(n+1,0)); 
        for(int i=1; i<=m; i++) {
            for(int j=1; j<=n; j++) {
                if(str1[i-1] == str2[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1]; 
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]); 
                }
            }
        }

        string ans = ""; // final SCS string store karne ke liye empty string
        int i = m, j = n; // dono strings ke last index se start karenge

        while(i>0 && j>0) { // jab tak dono strings ke characters bache hain
            if(str1[i-1] == str2[j-1]) {
                ans.push_back(str1[i-1]); // agar dono match karte hain toh ek hi baar add karo
                i--; // dono ek step peeche chale gaye
                j--;
            }
            else if(dp[i-1][j] > dp[i][j-1]) {
                ans.push_back(str1[i-1]); // agar str1 skip karne se lambi kahani banti hai toh str1 ka char add karo
                i--; // str1 ek step peeche
            }
            else {
                ans.push_back(str2[j-1]); // agar str2 skip karne se lambi kahani banti hai toh str2 ka char add karo
                j--; // str2 ek step peeche
            }
        }

        while(i>0) { // agar str1 ke characters bache hain
            ans.push_back(str1[i-1]); // unko add kar do
            i--;
        }

        while(j>0) { // agar str2 ke characters bache hain
            ans.push_back(str2[j-1]); // unko add kar do
            j--;
        }

        reverse(ans.begin(), ans.end()); // kyunki backtracking ulta hua tha, string ko reverse karna zaroori hai
        return ans; // final Shortest Common Supersequence string return kar do
    }
};

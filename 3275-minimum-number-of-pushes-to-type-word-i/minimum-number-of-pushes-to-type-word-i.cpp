class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        int pushes = 0;
        
        for(int i = 0; i < n; i++) {
            pushes += (i / 8) + 1;  
            // har 8 letters ke baad cost +1 ho jaata hai
        }
        
        return pushes;
    }
};

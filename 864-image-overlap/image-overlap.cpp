class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<pair<int,int>> ones1, ones2;

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(img1[i][j] == 1) ones1.push_back({i,j});
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(img2[i][j] == 1) ones2.push_back({i,j});
            }
        }
        
        unordered_map<long long,int> shiftCount;
        int maxOverlap = 0;
        
        for(auto &a : ones1){
            for(auto &b : ones2){
                int dx = b.first - a.first;
                int dy = b.second - a.second;
                long long key = ((long long)dx << 32) | (dy & 0xffffffff);
                maxOverlap = max(maxOverlap, ++shiftCount[key]);
            }
        }
        
        return maxOverlap;
    }
};

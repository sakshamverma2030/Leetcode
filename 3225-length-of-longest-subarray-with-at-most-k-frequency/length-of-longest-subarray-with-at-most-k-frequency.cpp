typedef long long int ll ; 
class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        ll n = nums.size();
        vector <ll> b(n+1,0);
        ll i = 1 ; 
        while(i<=n){
            b[i] = nums[i-1] ; 
            i++;
        }
        
        i = 1 ;
    ll j = 1 ;
    ll mv = 1 ;
    map <ll,ll> g ;
    g[b[1]]++;
    ll gg = 0 ;
    ll c = 0 ;
    while(i<=n && j<=n){
        if(i==j){
            // c = 0 ; 
            //g[b[i]]++;
            c = g[b[i]];
            if(c>k){
                i++;
                j++;
 
            }
            else{
                ll kk = 1 ;
                mv = max(kk,mv);
                j++;
                if(j<=n){
                	g[b[j]]++;
                }
            }
        } else {
            c = g[b[j]];
            if(c>k){
                //[i....j] is invalid but [i......j-1] was valid
                //so->[i+1...j-1] will also be valid hence
                //i++ and j--
 
                // # if(b[i]==g){
                // #     c--;
                // # }
                g[b[i]]--;
                i++;
 
                g[b[j]]--;
                j--;
 
                if(i>j){
                    j = i ;
                    g[b[i]]++;
                }
                //cout<<i<<" "<<j;
                //cout<<'\n';
            }
            else {
                ll kk = abs(i-j) + 1 ;
                //cout<<i<<" "<<j;
                //cout<<'\n';
                j++;
 
                if(j<=n){
                    g[b[j]]++;
                }
 
                mv = max(kk,mv);
            }
        }
    }
        
        int y = mv ; 
        
        
        
        
        return y ; 
    }
};
typedef long long ll;
class Solution {
public:
    int rearrangeSticks(int n, int k) {
        if(k>n) return 0;
        int mod = 1e9+7;
        vector<vector<ll>> dp(n+1,vector<ll>(k+1));
        dp[0][0] = 1;
        
        for(int i=1;i<=n;i++){
            for(int j=0;j<=k;j++){
                if(j>0) dp[i][j] = (dp[i][j]+dp[i-1][j-1])%mod;
                dp[i][j] = (dp[i][j]+(i-1)*dp[i-1][j])%mod; 
            }
        }

        return dp[n][k];

    }
};
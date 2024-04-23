class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n+2,vector<int>(n+2,0));
        for(int st = n; st>=1; st--){
            for(int end=st; end<=n; end++){
                if(st==end) continue;
                else{
                    int mx = INT_MAX;
                    for(int k=st;k<=end;k++){
                        mx = min(mx,k+max(dp[st][k-1],dp[k+1][end]));
                    }
                    dp[st][end] = mx;
                }
            }
        }
        return dp[1][n];
    }
};
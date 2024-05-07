class Solution {
public:
    int dp[1002][1002];
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        string r = s;
        reverse(r.begin(),r.end());
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1]==r[j-1])
                    dp[i][j] = 1+dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
            }
        }
        return dp[n][n];
    }  
};
class Solution {
public:
    int climbStairs(int n) {

        int dp[46] = {0};
        dp[0]=1;
        for(int i=0;i<=n;i++){
            if(i+1 <= n)
                dp[i+1] += dp[i];
            if(i+2 <= n)
                dp[i+2] += dp[i]; 
        }
        
        return dp[n];
    }
};
class Solution {
public:
    int dp[5001][2];
    int solve(vector<int>& prices, int i, int buy){
        if(i>=prices.size())
            return 0;
        
        if(dp[i][buy]!=-1)
            return dp[i][buy];

        int ans = 0;
        if(buy){
            ans = -prices[i]+solve(prices,i+1,false);
        }else{
            ans += prices[i]+solve(prices,i+2,true);
        }
        ans = max(ans,solve(prices,i+1,buy));
        return dp[i][buy]=ans;
    }

    int maxProfit(vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        return solve(prices,0,1);
    }
};
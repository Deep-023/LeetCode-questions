class Solution {
public:
    
    int solve(vector<vector<vector<int>>>& dp, int buy, int cap, int ind, int n, vector<int>& prices)
    { 
        if(cap==0|| ind==n)
            return 0;
    
        if(dp[ind][buy][cap] != -1)
            return dp[ind][buy][cap];
    
        int profit;
    
        if(buy)
            profit = max(solve(dp,1,cap,ind+1,n,prices), -prices[ind]+solve(dp,0,cap,ind+1,n,prices));
        else
            profit = max(solve(dp,0,cap,ind+1,n,prices), prices[ind]+solve(dp,1,cap-1,ind+1,n,prices));
    
        return dp[ind][buy][cap] = profit;
    }
    
    
    int maxProfit(int k, vector<int>& prices) {
        int n= prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2,vector<int>(k+1,-1)));
        return solve(dp,1,k,0,n,prices);
    }
};
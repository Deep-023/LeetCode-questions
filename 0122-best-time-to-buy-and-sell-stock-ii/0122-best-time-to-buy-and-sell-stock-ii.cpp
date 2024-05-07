class Solution {
public:
    int n;
    /*int solve(int idx, int lastBought, vector<int>& prices, vector<vector<int>>& dp){
        if(idx >= n) return 0;
        if(dp[idx][lastBought] != INT_MIN) return dp[idx][lastBought];

        int profit = 0, op1 = 0, op2 = 0, op3 = 0, op4 = 0;
        
        if(lastBought == -1){
            op1 = solve(idx+1, idx, prices, dp); // buy
            op2 = solve(idx+1, n+1, prices, dp); // don't buy
        }else{
            op3 = prices[idx] - prices[lastBought] + solve(idx+1, -1, prices, dp); // sell
            op4 = solve(idx+1, lastBought, prices, dp); // dont' sell
        }
        
        profit = max({op1, op2, op3, op4});
        
        return dp[idx][lastBought] = profit;
    }*/
    
    int maxProfit(vector<int>& prices) {
        n = prices.size();
        //vector<vector<int>> dp(n+1, vector<int>(n+1, INT_MIN));
        vector<pair<int,int>> dp(2,make_pair(0,0));
        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                if(buy){
                    dp[0].second = max(-prices[i]+dp[1].first,dp[1].second);
                }else{
                    dp[0].first = max(prices[i]+dp[1].second,dp[1].first);
                }
            }
            dp[1]=dp[0];
        }
        return dp[0].second;

        //return solve(0, -1, prices, dp);
    }
};
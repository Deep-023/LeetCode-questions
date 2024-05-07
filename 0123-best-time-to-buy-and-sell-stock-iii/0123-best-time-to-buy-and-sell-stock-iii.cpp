class Solution {
public:
    int dp[100001][2][2];
    int solve(vector<int>& prices,int k, int idx,int buy){
        if(idx>=prices.size() || k<0)
            return 0;
        
        if(dp[idx][buy][k]!=-1)
            return dp[idx][buy][k];
        
        int ans = 0;
        if(buy){
            int skip = solve(prices,k,idx+1,buy);
            int leliya = -prices[idx]+solve(prices,k,idx+1,!buy);
            ans = max(skip,leliya);
        }else{
            int skip = solve(prices,k,idx+1,buy);
            int bechdiya = prices[idx]+solve(prices,k-1,idx+1,!buy);
            ans = max(skip,bechdiya);
        }
        return dp[idx][buy][k]=ans;
    }
    int maxProfit(vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        return solve(prices,1,0,1);   
    }
};
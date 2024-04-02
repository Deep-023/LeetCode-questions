class Solution {
public:
    int pass[3] = {1,7,30};
    int solve(vector<int>& days, vector<int>& costs, int idx, int n, int lim, vector<int>& dp){
        
        if(idx>=n || lim>days[n-1])
            return 0;
        
        if(dp[lim] != -1)
            return dp[lim];
        
        int ans = 1e5;
        if(days[idx]>=lim){
            for(int i=0;i<3;i++){
                ans = min(ans,costs[i]+solve(days,costs,idx+1,n,days[idx]+pass[i],dp));
            }
        }else{
            ans = solve(days,costs,idx+1,n,lim,dp);
        }
        
        return dp[lim]=ans;
        
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        int m = days[n-1];
        vector<int> dp(m+1,-1);
        return solve(days,costs,0,n,days[0],dp);
    }
};
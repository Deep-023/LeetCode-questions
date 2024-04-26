class Solution {
public:
    int solve(vector<vector<int>>& grid, int i, int m, int prev, vector<vector<int>>&dp){
        if(i>=grid.size())
            return 0;
        
        if(dp[i][prev+1]!=-1){
            return dp[i][prev+1];
        }

        int ans = INT_MAX;
        for(int k=0;k<m;k++){
            if(prev != k){
                ans = min(ans,grid[i][k]+solve(grid,i+1,m,k,dp));
            }
        }
        
        return dp[i][prev+1]=ans;
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size(),m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m+1,-1));
        return solve(grid,0,m,-1,dp);
    }
};
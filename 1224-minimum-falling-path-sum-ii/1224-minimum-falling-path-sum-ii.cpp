#pragma GCC optimize("O3", "unroll-loops")
class Solution {
public:
    /*int solve(vector<vector<int>>& grid, int i, int m, int prev, vector<vector<int>>&dp){
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
    }*/
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size(),m=grid[0].size();
        //vector<vector<int>>dp(n,vector<int>(m+1,-1));
        //return solve(grid,0,m,-1,dp);
        vector<vector<int>>dp(n+1,vector<int>(m+2,INT_MAX));
        for(int i=0;i<m+2;i++) dp[n][i] = 0;

        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=-1;j--){
                for(int k=0;k<m;k++){
                    if(j != k){
                        dp[i][j+1] = min(dp[i][j+1],grid[i][k]+dp[i+1][k+1]);
                    }
                }
            }
        }

        return dp[0][0];

    }
};

auto init = [](){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
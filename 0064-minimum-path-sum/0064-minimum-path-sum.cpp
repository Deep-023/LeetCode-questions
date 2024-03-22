/*class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<int> dp(m,INT_MAX);
        dp[0] = grid[0][0];
        for(int i=1;i<m;i++){
            dp[i] = dp[i-1]+grid[0][i];
        }
    
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){ 
                if(j==0)
                    dp[j] = dp[j]+grid[i][j];
                else
                    dp[j] = grid[i][j]+min(dp[j-1],dp[j]);
            }
        }
        
        return dp[m-1];
        
    }
};*/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<int> dp(m);
        dp[m-1] = grid[n-1][m-1];
        for(int col=m-2; col>=0; col--){
            dp[col] = grid[n-1][col] + dp[col+1];
        }
        for(int row=n-2; row>=0; row--){
            dp[m-1] += grid[row][m-1];
            for(int col=m-2; col>=0; col--){
                dp[col] = grid[row][col] + min(dp[col], dp[col+1]);
            }
        }
        return dp[0];
    }
};
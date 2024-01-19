class Solution {
public:
    int solve(vector<vector<int>>& matrix,int n , int row, int col,vector<vector<int>>&dp){
        if(row>=n){
            return 0;
        }
        else if(col>=n || col<0)
            return 1e9;
        
        if(dp[row][col] != 1e9){
            return dp[row][col];
        }
        
        int ans = INT_MAX;
        if(col<n){
            ans = min(ans,solve(matrix,n,row+1,col-1,dp));
            ans = min(ans,solve(matrix,n,row+1,col,dp));
            ans = min(ans,solve(matrix,n,row+1,col+1,dp));
        }
        
        return dp[row][col] = ans+matrix[row][col];
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int ans = INT_MAX;
        int n = matrix.size();
        vector<vector<int>>dp(n,vector<int>(n,1e9));
        for(int i=0;i<n;i++)
            ans = min(ans,solve(matrix,n,0,i,dp));
        return ans;
        
        /*int n = matrix.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 1e9));

        // Initialize the last row of dp with the values from the matrix
        for (int i = 0; i < n; i++) {
            dp[n - 1][i] = matrix[n - 1][i];
        }

        // Start from the second last row and fill the dp table
        for (int row = n - 2; row >= 0; row--) {
            for (int col = 0; col < n; col++) {
                int a = (col-1 >= 0 ? dp[row + 1][col - 1] : 1e9);
                int b = (col+1 < n ? dp[row + 1][col + 1] : 1e9);
                dp[row][col] = matrix[row][col] + min({
                    a, dp[row + 1][col], b
                });
                 
            }
        }

        // Find the minimum value in the first row of dp
        int ans = *min_element(dp[0].begin(), dp[0].end());

        return ans;*/
    }
};
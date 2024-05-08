class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,1e8));
        for(int i=n-1;i>=0;i--)
            dp[n][i] = 0;
        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                dp[i][j] = min(dp[i+1][j],dp[i+1][j+1]);
                if(j>0)
                    dp[i][j] = min(dp[i][j],dp[i+1][j-1]);
                dp[i][j] += matrix[i][j];
            }
        }
        return *min_element(dp[0].begin(),dp[0].end());
    }
};
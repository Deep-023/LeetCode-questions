class Solution {
public:
    
    int solve(vector<vector<char>>& matrix, int i, int j, int& ans, vector<vector<int>>& dp){
        
        if(i>=matrix.size() || j>=matrix[0].size())
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int down = solve(matrix,i+1,j,ans,dp);
        int right = solve(matrix,i,j+1,ans,dp);
        int diag = solve(matrix,i+1,j+1,ans,dp);
        
        if(matrix[i][j]=='1'){
            dp[i][j] = 1+min(down,min(right,diag));
            ans = max(ans,dp[i][j]);
        }else{
            dp[i][j]=0;
        }
        
        return dp[i][j];
    }
    
    int maximalSquare(vector<vector<char>>& matrix) {
        int ans = 0;
        int n = matrix.size(),m=matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        solve(matrix,0,0,ans,dp);
        return ans*ans;
    }
};
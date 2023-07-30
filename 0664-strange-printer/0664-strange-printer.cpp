class Solution {
public:
    
    int solve(vector<vector<int>>& dp, int i, int j, int n, string s){
        
        if(i>j)
            return 0;
        if(i==j)
            return dp[i][j]=1;
        
        if (dp[i][j] != -1)
            return dp[i][j];
        
        
        int ans = 1+solve(dp,i+1,j,n,s);
        
        for(int k=i+1;k<=j;k++){
            if(s[k]==s[i])
            ans = min(ans, solve(dp,i,k-1,n,s)+solve(dp,k+1,j,n,s));
        }
        
        return dp[i][j] = ans;
    }
    
    int strangePrinter(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n,-1));
        return solve(dp,0,n-1,n,s);
    }
};
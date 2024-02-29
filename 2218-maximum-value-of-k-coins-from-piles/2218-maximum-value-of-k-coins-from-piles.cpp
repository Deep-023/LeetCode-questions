class Solution {
public:
    
    int solve(vector<vector<int>>& piles, int k, int i, vector<vector<int>>& dp){
        
        if( i>= piles.size() || k<=0){
            return 0;
        }
        
        if(dp[i][k] != -1)
            return dp[i][k];
        
        int ans = solve(piles,k,i+1,dp);
        int sum = 0;
        
        for(int j=0;j<piles[i].size();j++){
            sum += piles[i][j];
            if(k-j-1 >=0 ){
                ans = max(ans,sum+solve(piles,k-j-1,i+1,dp));
            }else{
                break;
            }
        }
        
        return dp[i][k]=ans;
        
    }
    
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size();
        vector<vector<int>> dp(n+1,vector<int>(k+1,-1));
        return solve(piles,k,0,dp);
    }
};
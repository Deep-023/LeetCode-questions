class Solution {
public:
    
    int solve(vector<int>& obstacles, int i, int currLane, vector<vector<int>>& dp){
        
        int n = obstacles.size()-1;
        if(i==n)
            return 0;
        
        if(dp[currLane][i]!=-1)
            return dp[currLane][i];
        
        if(obstacles[i+1] != currLane)
            return solve(obstacles,i+1,currLane,dp);
        
        int ans = INT_MAX;
        for(int k=1;k<=3;k++){
            if(k != obstacles[i] && currLane != k)
                ans = min(ans,1+solve(obstacles,i+1,k,dp));
        }
        
        return dp[currLane][i] = ans;
    }
    
    int minSideJumps(vector<int>& obstacles) {
        int n = obstacles.size();
        vector<vector<int>>dp(4,vector<int>(obstacles.size()+1,-1));
        
        dp[0][n-1]=0;dp[1][n-1]=0;dp[2][n-1]=0;dp[3][n-1]=0;
        
        for(int i=n-2;i>=0;i--){
            for(int j=1;j<4;j++){
                if(obstacles[i+1] != j)
                    dp[j][i] = dp[j][i+1];
                else{
                    int ans = INT_MAX;
                    for(int k=1;k<=3;k++){
                        if(k != obstacles[i] && j != k)
                            ans = min(ans,1+dp[k][i+1]);
                    }
                    dp[j][i] = ans;
                }
            }
        }
        
        
        return dp[2][0];
    }
};
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
        vector<vector<int>>dp(4,vector<int>(obstacles.size()+1,-1));
        return solve(obstacles,0,2,dp);
    }
};
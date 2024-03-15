 class Solution {
public:
   /* int check(vector<int>&cost , int i){
        
        if(i==cost.size())
            return 0;
            
        if(i>cost.size()){
            return 1e8;
        }
        
        int left = cost[i]+check(cost,i+1);
        int right = cost[i]+check(cost,i+2);
        return min(left , right);
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        return min(check(cost,0),check(cost,1));
    }*/
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>dp(n);
        dp[0] = cost[0];dp[1]=cost[1];
        
        for(int i=2;i<n;i++){
            dp[i] = cost[i] + min(dp[i-1],dp[i-2]); 
        }
        
        return min(dp[n-1],dp[n-2]);
    }
};
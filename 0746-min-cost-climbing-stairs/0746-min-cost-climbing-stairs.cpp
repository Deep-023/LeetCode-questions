#include <bits/stdc++.h> 
class Solution {
public:
    /*int check(vector<int>&cost , int i){
        
        if(i>=cost.size()){
            return 0;
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
        vector<int> dp(n+2,INT_MAX);
        
        for(int i=0;i<n;i++){
            dp[i] = dp[i] == INT_MAX ? 0 : dp[i];
            dp[i+1] = min(dp[i+1], dp[i]+cost[i]);
            dp[i+2] = min(dp[i+2], dp[i]+cost[i]);
            if(i==1){
                dp[i+1] = min(dp[i+1], cost[i]);
                dp[i+2] = min(dp[i+2], cost[i]);
            }
        }
        return dp[n];
    }
};
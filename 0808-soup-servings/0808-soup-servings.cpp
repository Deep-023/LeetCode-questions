class Solution {
public:
    
    double solve( vector<vector<double>>&dp, int a, int b, vector<vector<int>> prop){
        
        if(a<=0){
            if(b<=0)
                return 0.5;
            return 1;
        }
        
        if(b<=0)
            return 0;
        
        if(dp[a][b] != -1)
            return dp[a][b];
        
        double sum=0;
        
        for(int i=0;i<4;i++){
            sum += solve(dp,a-prop[i][0],b-prop[i][1], prop);
        }
        
        return dp[a][b] = sum/4;
        
    }
    
    double soupServings(int n) {
        if(n>=4850)
            return 1;
        
        vector<vector<double>>dp (n+1, vector<double>(n+1,-1));
        vector<vector<int>> prop {
        {100,0},
        {75,25},
        {50,50},
        {25,75}
    };
        return solve(dp,n,n,prop);  
    }
};
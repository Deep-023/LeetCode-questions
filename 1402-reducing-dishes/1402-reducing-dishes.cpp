class Solution {
public:
    int maxSatisfaction(vector<int>& satis) {
        sort(satis.begin(),satis.end());
        int n = satis.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        
        for(int i=n-1;i>=0;i--){
            for(int j=i;j>=0;j--){
                int incl = satis[i]*(j+1) + dp[i+1][j+1];
                int excl = dp[i+1][j];
                
                dp[i][j] = max(incl,excl);
            }
        }
        
        return dp[0][0];
    }
};
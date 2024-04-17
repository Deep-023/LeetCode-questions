class Solution {
public:
    int maxSatisfaction(vector<int>& satis) {
        sort(satis.begin(),satis.end());
        int n = satis.size();
        vector<int> dp(n+1,0);
        
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=i;j++){
                int incl = satis[i]*(j+1) + dp[j+1];
                int excl = dp[j];
                
                dp[j] = max(incl,excl);
            }
        }
        
        return dp[0];
    }
};
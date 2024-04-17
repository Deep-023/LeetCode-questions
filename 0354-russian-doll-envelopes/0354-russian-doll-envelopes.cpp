class Solution {
public:
    static bool comp(vector<int>& a, vector<int>&b){
        if(a[0]==b[0]){
            return a[1]>b[1];
        }
        return a[0]<b[0];
    }
    
    int maxEnvelopes(vector<vector<int>>& env) {
        sort(env.begin(),env.end(),comp);
        int n = env.size();
        /*vector<int>dp(n,1);
        int maxi = 0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(env[j][0]<env[i][0] && env[j][1]<env[i][1] && dp[i]<dp[j]+1)
                    dp[i]=dp[j]+1;
            }
            maxi = max(maxi, dp[i]);
        }*/
        vector<int>lis;
        
        for(int i=0; i<n; i++){
            auto it = lower_bound(lis.begin(), lis.end(), env[i][1]);
            if(it==lis.end()){lis.push_back(env[i][1]);}
            else{
                *it = env[i][1];
            }
        }
        return lis.size();

        
    }
};
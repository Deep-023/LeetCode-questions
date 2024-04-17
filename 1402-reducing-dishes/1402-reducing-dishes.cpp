class Solution {
public:
    int maxSatisfaction(vector<int>& satis) {
        sort(satis.begin(),satis.end());
        int n = satis.size();
        /*vector<int> dp(n+1,0);
        
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=i;j++){
                int incl = satis[i]*(j+1) + dp[j+1];
                int excl = dp[j];
                
                dp[j] = max(incl,excl);
            }
        }*/
        
        int ans = 0;
        int k=1,cut=-1;
        vector<int> sum(n,0);
        for(int i=0;i<n;i++){
            if(satis[i]>0)
                ans = ans+(satis[i]*k++);
            else
                cut=i;
            sum[n-1-i] = satis[n-1-i] + (i==0 ? 0 : sum[n-i]);
        }
        int mxans = ans;
        for(int i=cut;i>=0;i--)
        {
            ans += sum[i];
            mxans = max(ans,mxans);
        }
        
        return mxans;
    }
};
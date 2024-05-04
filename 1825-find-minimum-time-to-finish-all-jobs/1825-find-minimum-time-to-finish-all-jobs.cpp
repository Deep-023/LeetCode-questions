class Solution {
public:
    int dp[13][(1<<13)];
    int res[(1<<13)];
    int workers,n;

    int solve(vector<int>& jobs, int k ,int mask){
        if(mask==((1<<n)-1))
            return 0;
        if(k>=workers)
            return 1e9;

        if(dp[k][mask]!=-1)
            return dp[k][mask];
        
        int nwmask = 0;
        for(int i=0;i<n;i++){
            if((mask&(1<<i))==0)
                nwmask |= 1<<i;
        }
        int ans=1e9;
        for(int i=nwmask;i;i=(i-1)&nwmask) //(i-1)&nwmask is used to find all possible subset of nwmask
        {
            if((i&mask)==0){
                ans = min(ans,max(res[i],solve(jobs,k+1,mask|i)));
            }
        }
        return dp[k][mask]=ans;
    }   

    int minimumTimeRequired(vector<int>& jobs, int k) {
        n = jobs.size();
        workers = k;
        for(int i=0;i<(1<<n);i++){
            res[i]=0;
            for(int j=0;j<n;j++){
                if(i&(1<<j))
                    res[i]+=jobs[j];
            }
        }
        memset(dp,-1,sizeof(dp));
        return solve(jobs,0,0);
    }
};
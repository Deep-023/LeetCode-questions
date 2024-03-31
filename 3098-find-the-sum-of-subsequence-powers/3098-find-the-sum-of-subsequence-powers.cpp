class Solution {
public:
    int dp[52][52][52][52];
    int mod = 1e9+7;
    long long solve(vector<int>& nums, int k, int idx, int last, int mn, int mx){
        
        if(k==0){
            return abs(nums[mx]-nums[mn]);
        }
        if(idx>=nums.size())
            return 0;
        
        if(dp[last+1][mn+1][mx+1][k] != -1)
            return dp[last+1][mn+1][mx+1][k];
        
        long long ans = solve(nums,k,idx+1,last,mn,mx);
        ans = ans%mod;
        if(k>=1){
            if(last != -1 && (mn == -1 || mn == -1  || abs(nums[mx]-nums[mn]) > abs(nums[idx]-nums[last])))
                ans += solve(nums,k-1,idx+1,idx,last,idx);
            else
                ans += solve(nums,k-1,idx+1,idx,mn,mx);
            ans = ans%mod;
        }
        return dp[last+1][mn+1][mx+1][k]=ans%mod;
    }
    
    int sumOfPowers(vector<int>& nums, int k) {
        memset(dp,-1,sizeof(dp));
        sort(nums.begin(),nums.end());
        return solve(nums,k,0,-1,-1,-1);
    }
};
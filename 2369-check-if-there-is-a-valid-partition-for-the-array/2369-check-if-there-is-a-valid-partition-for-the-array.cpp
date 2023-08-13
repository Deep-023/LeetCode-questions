class Solution {
public:
    
    vector<int> dp;
    bool solve(vector<int>& nums, int idx, int n){
        if(n==0)
            return true;
        
        if(dp[n]!=-1)
            return dp[n];
        
        bool ans1=0,ans2=0;
        if(n>=2 && nums[idx]==nums[idx+1]){
            ans1 = solve(nums,idx+2,n-2);
            if(n>=3 && nums[idx]==nums[idx+2]){
                ans2= solve(nums,idx+3,n-3);
            }
        }
        else if(n>=3 && nums[idx]==nums[idx+1]-1 && nums[idx+1]==nums[idx+2]-1 )
            ans1 = solve(nums,idx+3,n-3);
        
        return dp[n] = ans1 || ans2;
    }
    
    bool validPartition(vector<int>& nums) {
        int n= nums.size();
        dp.assign(n+1,-1);
        return solve(nums,0,n);
    }
};
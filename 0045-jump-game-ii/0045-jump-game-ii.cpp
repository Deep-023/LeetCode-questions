class Solution {
public:
    vector<int> dp;
    
    int solve(int index, vector<int>& nums, int n) {
        if(index==n){
            return dp[index] = 0;
        }
        if(index>n){
            return 1e5;
        }
        if(dp[index] != -1){
            return dp[index];
        }
        
        int minCount = 1e5;
        
        for(int i=1;i<=nums[index];i++){
            int num = 1+solve(index+i,nums,n);
            minCount = min(minCount,num);
        }
        return dp[index] = minCount;
    }
        
    int jump(vector<int>& nums) {
        int n = nums.size();
        dp.assign(n, -1); 
        return solve(0, nums,n-1);
    }
};

/*class Solution {
public:

    int f(int ind,vector<int> &a,vector<int> &dp)
    {
        if(ind==a.size()-1)
            return dp[ind]=0;
        if(ind>a.size()-1)
            return 1e5;

        if(dp[ind]!=-1)
            return dp[ind];

        int mn=1e5;

        for(int i=1;i<=a[ind];i++)
        {
            int p=1+f(ind+i,a,dp);
            mn=min(mn,p);
        }
        return dp[ind]=mn;
    }

    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        return f(0,nums,dp);
    }
};*/
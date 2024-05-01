class Solution {
public:
    int n;
    int dp[305][305];

    int solve(vector<int>&nums , int i, int j){
        if(i>j)
            return 0;
        
        if(i==j){
            int temp = nums[i];
            if(i-1>=0) temp*=nums[i-1];
            if(j+1<n) temp*=nums[j+1];
            return temp;
        }

        if(dp[i][j]!=-1)
            return dp[i][j];

        long long res = 0;
        for(int k=i;k<=j;k++){
            long long temp = nums[k];
            if(i-1>=0) temp*=nums[i-1];
            if(j+1<n) temp*=nums[j+1];
            res = max(res,temp+solve(nums,k+1,j)+solve(nums,i,k-1));
        }
        return dp[i][j] = res;
    }

    int maxCoins(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        n = nums.size();
        return solve(nums,1,n-2);
    }
};
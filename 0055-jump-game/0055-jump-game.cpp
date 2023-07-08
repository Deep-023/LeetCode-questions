class Solution {
public:
    vector<int>dp;
    bool solve(int index, vector<int>& nums){
        
        if(index == nums.size()-1)
            return true;
        if(index > nums.size()-1)
            return false;
        if(dp[index]!= -1)
            return dp[index]==1;
        
        for(int i=1;i<=nums[index];i++){
            if(solve(index+i, nums)){
                dp[index]=1;
                return true;
            }
        }
        dp[index]=0;
        return false;
        
    }
        
        
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        dp.assign(n,-1);
        return solve(0,nums);
    }
};
class Solution {
public:
    pair<int,int> dp[2002][2002];
    pair<int,int> solve(vector<int>& nums,int i, int j){
        if(i>=nums.size()|| j>=nums.size())
            return {1,1};

        if(dp[i][j]!=make_pair(-1,-1)){
            return dp[i][j];
        }

        pair<int,int> ans = {0,0};
        if(nums[i]<nums[j]){
            auto temp = solve(nums,j,j+1);
            ans = {temp.first+1,temp.second};
        }

        auto temp = solve(nums,i,j+1);
        if(temp.first == ans.first){
            ans.second += temp.second;
        }else if(temp.first > ans.first)
            ans = temp;

        return dp[i][j]=ans;
    }

    int findNumberOfLIS(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        nums.insert(nums.begin(),-1e7);
        return solve(nums,0,1).second;
    }
};
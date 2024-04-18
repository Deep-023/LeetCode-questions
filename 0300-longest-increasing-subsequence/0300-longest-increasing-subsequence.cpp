class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> dp(n,1);
        /*for(int i=0;i<n;i++){
            auto itr = lower_bound(list.begin(),list.end(),nums[i]);
            if(itr == list.end())list.push_back(nums[i]);
            else *itr = nums[i];
        }
        return list.size();*/
        
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i] && dp[i]<dp[j]+1)
                dp[i] = dp[j]+1;
            }
        }
        
        return *max_element(dp.begin(),dp.end());
    }
};
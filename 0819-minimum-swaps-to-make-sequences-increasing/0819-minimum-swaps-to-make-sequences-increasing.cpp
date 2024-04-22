class Solution {
public:
    vector<vector<int>>dp;
    int solve(vector<int>& nums1, vector<int>& nums2, int n , int swapped){
        if(n>=nums1.size()) return 0;

        if(dp[n][swapped]!=-1)
            return dp[n][swapped];

        int prev1 = nums1[n-1];
        int prev2 = nums2[n-1];

        if(swapped)
            swap(prev1,prev2);

        int ans=INT_MAX;
        if(nums1[n]>prev1 && nums2[n]>prev2){
            ans = solve(nums1,nums2,n+1,0);
        }
        if(nums1[n]>prev2 && nums2[n]>prev1){
            ans = min(ans,1+solve(nums1,nums2,n+1,1));
        }

        return dp[n][swapped]=ans;
    }
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.begin(),-1);
        nums2.insert(nums2.begin(),-1);

        dp.resize(nums1.size(),vector<int>(2,-1));
        return solve(nums1,nums2,1,0);
    }
};
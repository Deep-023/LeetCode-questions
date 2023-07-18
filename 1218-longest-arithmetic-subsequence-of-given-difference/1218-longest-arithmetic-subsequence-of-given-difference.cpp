class Solution {
public:
    
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int,int> dp;
        int ans=0;
        for(int i=0;i<arr.size();i++){
            dp[arr[i]]= dp[arr[i]-difference] + 1;
            ans = max(ans,dp[arr[i]]);
        }
        return ans;
    }
};
class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        int rn = ranges.size();
        vector<int> dp(rn,rn+1);
        dp[0]=0;
        for(int i=0;i<rn;i++){
            int start = max(i-ranges[i],0);
            int end = min(i+ranges[i], rn-1);
            for(int j=start;j<=end;j++){
                dp[j] = min(dp[j],1+dp[start]);
            }
        }
        return dp[rn-1]==rn+1 ? -1 : dp[rn-1];
    }
};
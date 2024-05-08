class Solution {
public:
    map<pair<int,int>,int>dp;
    int solve(vector<int>& cuts, int i, int j){
        if(i>=j)
            return 0;
        
        if(dp.count({i,j}))
            return dp[{i,j}];

        int ans = 1e7;
        for(int k=0;k<cuts.size();k++){
            if(cuts[k]>i && cuts[k]<j){
                ans = min(ans,solve(cuts,i,cuts[k])+solve(cuts,cuts[k],j));
            }
        }
        ans += (j-i);
        return dp[{i,j}] = (ans>=1e7 ? 0:ans);
    }
    int minCost(int n, vector<int>& cuts) {
        return solve(cuts,0,n);
    }
};
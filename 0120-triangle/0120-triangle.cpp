class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<triangle[i].size();j++){
                dp[i][j] = min(triangle[i][j]+dp[i+1][j],triangle[i][j]+dp[i+1][j+1]);
            }
        }
        return dp[0][0];
    }
};
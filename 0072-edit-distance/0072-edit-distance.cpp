class Solution {
public:
    int dp[502][502];
    int minDistance(string word1, string word2) {
        memset(dp,0,sizeof(dp));
        int n = word1.size(),m=word2.size();
        dp[n][m] = 0;
        for(int i=0;i<m;i++)
            dp[n][i] = m-i; 
        for(int i=0;i<n;i++)
            dp[i][m] = n-i; 

        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(word1[i]==word2[j])
                    dp[i][j] = dp[i+1][j+1];
                else{
                    int temp =INT_MAX;
                    temp = min({dp[i+1][j],dp[i][j+1],dp[i+1][j+1]});
                    dp[i][j]= temp+1;
                }
            }
        }
        return dp[0][0];
    }
};
class Solution {
public:
    bool solve(string& s1, string& s2, string& s3, int i, int j, int k, int n1, int n2, int n3, vector<vector<vector<int>>>& dp){
        if(k>=n3)
            return true;
        if((i>=n1 && n1>0) && (j>=n3 && n2>0))
            return false;
        
        if(dp[i][j][k]!= -1)
            return dp[i][j][k];
        
        if(i<n1 && s1[i]==s3[k]){
            if(solve(s1,s2,s3,i+1,j,k+1,n1,n2,n3,dp))
                return dp[i][j][k]=true;
        }
        if(j<n2 && s2[j]==s3[k]){
            if(solve(s1,s2,s3,i,j+1,k+1,n1,n2,n3,dp))
                return dp[i][j][k]=true;
        }
        return dp[i][j][k]=false;
        
        
    }
    bool isInterleave(string s1, string s2, string s3) {
        int n1=s1.size(), n2=s2.size();
        int n3 = s3.size();
        if(n1+n2 != n3)
            return false;
        vector<vector<vector<int>>> dp(n1+1, vector<vector<int>>(n2+1, vector<int>(n3+1,-1)));
        return solve(s1,s2,s3,0,0,0,n1,n2,n3,dp);
        
    }
};
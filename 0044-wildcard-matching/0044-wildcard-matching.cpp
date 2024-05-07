class Solution {
public:
    vector<vector<int>>dp;
    bool solve(string& s, string& p, int i, int j){
        if (i<0 && j<0)
            return true;
        else if (i>=0 && j<0)
            return false;
        else if (i<0 && j>=0){
            for(int k=j;k>=0;k--)
                if(p[k]!='*')
                    return false;
            return true;
        }

        if(dp[i][j]!=-1)
            return dp[i][j];

        if(s[i]==p[j] || p[j]=='?')
            return dp[i][j]=solve(s,p,i-1,j-1);
        else if(p[j]=='*')
            return dp[i][j]=solve(s,p,i,j-1) || solve(s,p,i-1,j);
        
        return dp[i][j]=false;
    }
    bool isMatch(string s, string p) {
        int n = s.size(), m=p.size();
        dp = vector<vector<int>>(n,vector<int>(m,-1));
        return solve(s,p,n-1,m-1);
    }
};
class Solution {
public:
    int dp[32][32][32];
    bool solve(string& s1, string& s2, int i, int j, int n){
        if(n==0) return true;

        if(dp[i][j][n] != -1)
            return dp[i][j][n];

        for(int i1=i,j1=j;i1<=i+n;i1++,j1++){
            if(i1==i+n) return dp[i][j][n]=true;
            if(s1[i1]!=s2[j1]) break;
        }
        vector<int> arr(26);
        for(int k=0;k<n;k++){
            arr[s1[i+k]-'a']++;
            arr[s2[j+k]-'a']--;
        }

        for(int k=0;k<26;k++)
            if(arr[k] != 0) return dp[i][j][n]=false;

        for(int k=1;k<n;k++){
            if(solve(s1,s2,i,j,k) && solve(s1,s2,i+k,j+k,n-k))
                return dp[i][j][n]=true;
            
            if(solve(s1,s2,i+k,j,n-k) && solve(s1,s2,i,j+n-k,k))
                return dp[i][j][n]=true;
        }   

        return dp[i][j][n]=false;
    }
    bool isScramble(string s1, string s2) {
        if(s1.size() != s2.size()) return false;
        memset(dp,-1,sizeof(dp));
        return solve(s1,s2,0,0,s1.size());
    }
};
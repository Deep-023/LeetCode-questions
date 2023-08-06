class Solution {
public:
    int numMusicPlaylists(int n, int goal, int k) {
        vector<vector<long>>dp (goal+1, vector<long>(n+1,0)); //here i is length of playlist and j is no. of unique songs 
        dp[0][0]=1;  //when there is no song i.e empty playlist
        int mod = 1e9 + 7 ;
        cout<<mod;
        for(int i=1;i<=goal;i++){
            for(int j=1;j<=min(n,i);j++){
                dp[i][j] = (dp[i-1][j-1]*(n-j+1)) % mod; //adding an element can make n-(j-1) combination 
                if(j>k)
                    dp[i][j] = (dp[i][j] +dp[i-1][j]*(j-k)) % mod; //the case of dub j wont change
            }
        }
        return dp[goal][n];
        
    }
};
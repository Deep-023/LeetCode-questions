class Solution {
public:

    int solve(int arr[][10],int m, int n, int i,vector<vector<int>>& dp, int last){
        if(i>=m)
            return 0;

        if(dp[i][last+1] != -1)
            return dp[i][last+1];

        int ans = INT_MAX;
        for(int k=0;k<10;k++){
            if(k != last)
                ans = min(ans, n-arr[i][k]+solve(arr,m,n,i+1,dp,k));
        }
        return dp[i][last+1]=ans;
    }

    int minimumOperations(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int last = -1;
        int arr[m][10];
        memset(arr,0,sizeof(arr));
        for(int j=0;j<m;j++){
            for(int i=0;i<n;i++){
                arr[j][grid[i][j]]++;
            }
        }
        vector<vector<int>>dp(m,vector<int>(11,-1));
        int ans = solve(arr,m,n,0,dp,-1);

        return ans;
    }
};

/*
4 5 0 1
1 9 0 8
2 2 5 3
2 0 9 3

2+3+2+2
*/
class Solution {
public:
    int dp[41][41];
    int mx[41][41];

    int solve(vector<int>&arr, int i, int j){
        if(i==j)
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int sum = INT_MAX;
        for(int k=i;k<j;k++){
            sum = min(sum, mx[i][k]*mx[k+1][j] + solve(arr,i,k)+ solve(arr,k+1,j));
        }
        return dp[i][j]=sum;
    }

    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;i++){
            int maxi = arr[i];
            for(int j=i;j<n;j++){
                mx[i][j] = j>i ? max(mx[i][j-1],arr[j]) : arr[i]; 
            }
        }
        return solve(arr,0,n-1);
    }
};
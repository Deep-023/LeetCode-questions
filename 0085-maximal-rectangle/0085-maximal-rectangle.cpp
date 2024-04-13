class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size(), m=matrix[0].size();
        vector<vector<int>> preSum(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(matrix[i][j]=='1')
                    preSum[i][j] = 1 + (j>0 ? preSum[i][j-1] : 0);
        
        int ans = 0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(preSum[i][j] > 0){
                    int mn = INT_MAX;
                    for(int k=i;k<n;k++){
                        if(preSum[k][j]==0)
                            break;
                        mn = min(mn,preSum[k][j]);
                        ans = max(ans,mn*(k-i+1));
                    }
                }
            }
        }
        
        return ans;
        
        
    }
};
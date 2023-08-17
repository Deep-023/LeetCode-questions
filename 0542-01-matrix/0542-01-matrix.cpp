class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m= mat.size();
        int n = mat[0].size();
        vector<vector<int>> ans(m, vector<int>(n,0));
        ans[0][0] = mat[0][0]==0 ? 0 : 10005;
        for(int i=1;i<m;i++){
            if(mat[i][0]==1)
                ans[i][0] = ans[i-1][0]+1;
        }
        for(int j=1;j<n;j++){
            if(mat[0][j]==1)
                ans[0][j] = ans[0][j-1]+1;
        }
        
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(mat[i][j]==1)
                   ans[i][j] = min(ans[i-1][j],ans[i][j-1])+1;
            }
        }
        
        for (int j = n - 2; j >= 0; j--) {
            if (ans[m - 1][j] != 0) ans[m - 1][j] = min(ans[m - 1][j], ans[m - 1][j + 1] + 1);
        }
        
        for (int i = m - 2; i >= 0; i--) {
            if (ans[i][n - 1] != 0) ans[i][n - 1] = min(ans[i][n - 1], ans[i + 1][n - 1] + 1);
        }
        
        
        for(int i=m-2;i>=0;i--){
            for(int j=n-2;j>=0;j--){
                if(mat[i][j]==1){
                    ans[i][j] = min(ans[i][j],(min(ans[i+1][j],ans[i][j+1])+1));
                }
            }
        }
        return ans;
    }
};
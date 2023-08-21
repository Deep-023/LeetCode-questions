class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>>ans(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int q = i-k <0 ? 0 : i-k; 
                for(;q<m && q<=i+k ; q++){
                    int r = j-k <0 ? 0 : j-k;
                    for(;r<n && r<=j+k; r++){
                        ans[i][j] += mat[q][r];
                    }
                }
            }
        }
        return ans;
    }
};